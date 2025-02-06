/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:21:45 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/06 16:00:28 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_dir(t_mini *sh, char *path, char ***envp)
{
	char	**env;
	char	*temp;

	temp = NULL;
	env = ft_calloc(2, sizeof(char *));
	temp = getcwd(temp, SIZE);
	if (chdir(path))
	{
		perror("SHELL-E: cd");
		sh->error = 42;
	}
	else
	{
		env[0] = ft_strjoin("OLDPWD=", temp);
		bi_export(sh, env, envp);
		temp = free_ptr(temp);
		env[0] = free_ptr(env[0]);
		temp = getcwd(temp, SIZE);
		env[0] = ft_strjoin("PWD=", temp);
		bi_export(sh, env, envp);
		sh->error = 0;
	}
	temp = free_ptr(temp);
	env[0] = free_ptr(env[0]);
}

char	*default_path(char **envp)
{
	int	count;
	char	*path;

	count = 0;
	while (envp && ft_strncmp(envp[count], "HOME=", 5))
		count++;
	path = *(envp + count) + 5;
	return (path);
}

void	bi_cd(t_mini *sh, char **args, char ***envp)
{
	if (args[1] && !args[2])
		put_dir(sh, args[1], envp);
	else if (!args[1])
		put_dir(sh, default_path(*envp), envp);
	else
	{
		ft_putstr_fd("", 2);
		sh->error = 42;
	}
}