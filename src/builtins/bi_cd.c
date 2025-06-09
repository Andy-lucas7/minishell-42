/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:21:45 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/13 11:07:22 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_dir(t_mini *sh, char *path, char ***envp)
{
	char	**env;
	char	*temp;

	temp = NULL;
	env = ft_calloc(3, sizeof(char *));
	env[0] = ft_strdup("expt");
	temp = getcwd(temp, BFF_SIZE);
	if (chdir(path))
	{
		perror(PROMPT_MSG"cd");
		sh->error = 1;
	}
	else
	{
		env[1] = ft_strjoin("OLDPWD=", temp);
		bi_export(sh, env, envp);
		temp = free_ptr(temp);
		env[1] = free_ptr(env[1]);
		temp = getcwd(temp, BFF_SIZE);
		env[1] = ft_strjoin("PWD=", temp);
		bi_export(sh, env, envp);
		sh->error = 0;
	}
	temp = free_ptr(temp);
	env = free_mat(env);
}

static char	*default_path(char **envp)
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
	else if (!args[1])
		change_dir(sh, default_path(*envp), envp);
	else
	{
		ft_putstr_fd(PROMPT_MSG"cd: invalid usage\n", 2);
		sh->error = 1;
	}
}
