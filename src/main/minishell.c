/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:46:53 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/20 11:47:59 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "token.h"

// pesquisar sobre parsing
// pesquisar sobre tokenização

// Função para unir diretórios e comandos
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

	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
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

// Executa um comando com base nos argumentos e ambiente
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

// Divide tokens em um array de argumentos para execve
char	**convert_tokens_to_args(t_token *tokens)
{
	t_token	*current = tokens;
	char	**args;
	int		count = 0;
	int		i = 0;

	while (current)
	{
		if (current->type == WORD)
			count++;
		current = current->next;
	}

	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (NULL);

	current = tokens;
	while (current)
	{
		if (current->type == WORD)
			args[i++] = strdup(current->value);
		current = current->next;
	}
	args[i] = NULL;
	return (args);
}

void	free_args(char **args)
{
	int	i = 0;

	if (!args)
		return ;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		free(tmp->value);
		free(tmp);
	}
}

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
	t_minishell	shell;
	t_token		*current;

	(void)argc;
	(void)argv;
	while (1)
	{
		shell.input = get_prompt();
		if (!shell.input)
		{
			printf("exit\n");
			break ;
		}
		if (*(shell.input))
		{
			shell.tokens = NULL;
			tokenizer(&shell);
			current = shell.tokens;
			while (current)
				current = current->next;
			if (shell.tokens && shell.tokens->type == WORD)
			{
				char **args = convert_tokens_to_args(shell.tokens);
				execute_command(args, envp);
				free_args(args);
			}

			free_tokens(shell.tokens);
		}
		free(shell.input);
	}
	return (EXIT_SUCCESS);
}

