/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:21:45 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/10 16:59:07 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_dir(t_mini *sh, char *path, char ***envp)
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

char	*default_path(char **envp)
{
	char	*path;

	while (envp && ft_strncmp(*envp, "HOME=", 5))
		envp++;
	path = *envp + 5;
	return (path);
}

void	bi_cd(t_mini *sh, char **args, char ***envp)
{
	if (args[1] && !args[2])
		change_dir(sh, args[1], envp);
	if (!ft_strncmp(args[1], "$PWD", 4))
		sh->error = 1;
	else if (!args[1] && !args[2])
		change_dir(sh, default_path(*envp), envp);
	else
	{
		ft_putstr_fd("-minishell: cd: invalid usage\n", 2);
		sh->error = 1;
	}
}
