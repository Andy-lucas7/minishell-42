/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-do <jreis-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:21:45 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/12 17:54:30 by jreis-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*default_path(char **envp)
{
	char	*path;

	while (envp && ft_strncmp(*envp, "HOME=", 5))
		envp++;
	path = *envp + 5;
	return (path);
}

static void	change_dir(t_mini *sh, char *path, char ***envp)
{
	char	**env;
	char	*temp;

	temp = NULL;
	env = ft_calloc(3, sizeof(char *));
	env[0] = ft_strdup("expt");
	temp = getcwd(temp, BUFFER_SIZE);
	if (chdir(path))
	{
		perror("SHELL-E: cd");
		sh->error = 1;
	}
	else
	{
		env[1] = ft_strjoin("OLDPWD=", temp);
		bi_export(sh, env, envp);
		temp = free_ptr(temp);
		env[1] = free_ptr(env[1]);
		temp = getcwd(temp, BUFFER_SIZE);
		env[1] = ft_strjoin("PWD=", temp);
		bi_export(sh, env, envp);
		sh->error = 0;
	}
	temp = free_ptr(temp);
	env = free_mat(env);
}

static void	change_dir_tild(t_mini *sh, char *path, char ***envp)
{
	char	*temp_path;
	char	**env;

	env = ft_calloc(3, sizeof(char *));
	env[0] = ft_strdup("expt");
	temp_path = NULL;
	temp_path = getcwd(temp_path, BUFFER_SIZE);
	env[1] = ft_strjoin("OLDPWD", temp_path);
	path++;
	change_dir(sh, default_path(*envp), envp);
	if (chdir(path))
	{
		perror("SHELL-E: cd");
		sh->error = 1;
	}
	else
	{
		change_dir(sh, path, envp);
		bi_export(sh, env, envp);
		sh->error = 0;
	}
	env = free_mat(env);
	temp_path = free_ptr(temp_path);
}

void	bi_cd(t_mini *sh, char **args, char ***envp)
{
	if (args[1] && !args[2])
	{
		if (args[1][0] == '~')
			change_dir_tild(sh, args[1], envp);
		else
			change_dir(sh, args[1], envp);
	}
	else if (!args[1])
		change_dir(sh, default_path(*envp), envp);
	else
	{
		ft_putstr_fd("-minishell: cd: invalid usage\n", 2);
		sh->error = 1;
	}
}
