/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:46:53 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/09 21:24:52 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// pesquisar sobre parsing
// pesquisar sobre tokenização

static char	*join_path(const char *dir, const char *cmd)
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

static char	*find_command(const char *cmd, char **envp)
{
	char	*path_env = NULL;
	char	**paths;
	char	*full_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path_env)
		return (NULL);
	paths = malloc(sizeof(char *) * 256);
	if (!paths)
		return (NULL);
	i = 0;
	paths[i] = strtok(path_env, ":");
	while (paths[i] && i < 255)
		paths[++i] = strtok(NULL, ":");
	i = -1;
	while (paths[++i])
	{
		full_path = join_path(paths[i], cmd);
		if (full_path && access(full_path, X_OK) == 0)
		{
			free(paths);
			return (full_path);
		}
		free(full_path);
	}
	free(paths);
	return (NULL);
}

static void	execute_command(char **args, char **envp)
{
	pid_t	pid;
	int		status;
	char	*cmd_path;

	cmd_path = find_command(args[0], envp);
	if (!cmd_path)
	{
		fprintf(stderr, "minishell: %s: command not found\n", args[0]);
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
		waitpid(pid, &status, 0);
	else
		perror("fork");
	free(cmd_path);
}

static char	**tokenize_input(char *input)
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
		args[++i] = strtok(NULL, " ");
	args[i] = NULL;
	return (args);
}

static char	*get_prompt(void)
{
	char	*input;

	input = readline("\033[0;36mMinishell: \033[0m");
	if (input && *input)
		add_history(input);
	return (input);
}

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
				break ;
			if (args)
				execute_command(args, envp);
			free(args);
		}
		free(input);
	}
	return (EXIT_SUCCESS);
}
