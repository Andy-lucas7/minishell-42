/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:38 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/22 20:33:32 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

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

