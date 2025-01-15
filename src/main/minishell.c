/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:46:53 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/14 15:05:52 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// pesquisar sobre parsing
// pesquisar sobre tokenização

char	*join_path(const char *dir, const char *cmd)
{
	char	*path;
	int		len;

	len = strlen(dir) + strlen(cmd) + 2;
	path = malloc(len);
	if (!path)
		return (NULL);
	snprintf(path, len, "%s/%s", dir, cmd);
	return (path);
}

// Retorna a variável PATH do ambiente
char	*get_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

// Cria uma lista de paths a partir do PATH
char	**get_paths(const char *path_env)
{
	char	**paths;
	char	*token;
	char	*copy;
	int		i;

	copy = strdup(path_env);
	if (!copy)
		return (NULL);
	paths = malloc(sizeof(char *) * 256);
	if (!paths)
	{
		free(copy);
		return (NULL);
	}
	i = 0;
	token = strtok(copy, ":");
	while (token && i < 255)
	{
		paths[i] = strdup(token); // Duplica cada token para evitar problemas de memória
		if (!paths[i++])
		{
			free_paths(paths);
			free(copy);
			return (NULL);
		}
		token = strtok(NULL, ":");
	}
	paths[i] = NULL;
	free(copy); // Libera a cópia original
	return (paths);
}

// Procura o comando nos diretórios do PATH
char	*find_command(const char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	char	*path_env;
	int		i;

	path_env = get_path_env(envp);
	if (!path_env)
		return (NULL);
	paths = get_paths(path_env);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
		{
			free_paths(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

void	execute_command(char **args, char **envp)
{
	pid_t	pid;
	int		status;
	char	*cmd_path;

	cmd_path = find_command(args[0], envp);
	if (!cmd_path)
	{
		printf("\033[1;36mMinishell:\033[0m %s: command not found\n", args[0]);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, args, envp) == -1)
		{
			perror("minishell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
		perror("fork");
	free(cmd_path);
}

// Divide a entrada em tokens
char	**tokenize_input(char *input)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char *) * 256);
	if (!args)
	{
		perror("malloc");
		return (NULL);
	}
	i = 0;
	args[i] = strtok(input, " ");
	while (args[i] && i < 255)
	{
		args[++i] = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}

// Captura a entrada do usuário
char	*get_prompt(void)
{
	char	*input;

	input = readline("\033[1;36mMinishell: \033[0m");
	if (input && *input)
		add_history(input);
	return (input);
}

// Função principal
int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**args;

	(void)argc;
	(void)argv;
	while (1)
	{
		input = get_prompt();
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
		{
			args = tokenize_input(input);
			if (args && strcmp(args[0], "exit") == 0)
			{
				free(args);
				break ;
			}
			if (args)
				execute_command(args, envp);
			free(args);
		}
		free(input);
	}
	return (EXIT_SUCCESS);
}
