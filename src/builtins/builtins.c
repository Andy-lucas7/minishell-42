/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:16:29 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/16 16:09:59 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins(t_mini *sh, char ***envp, char **args, int **fd)
{
	if (fd)
		free_fd(fd);
	if (!args || !*args || !*envp)
		return (-1);
	else if (!ft_strncmp(*args, "echo", 5))
		bi_echo(sh, args);
	else if (!ft_strncmp(*args, "cd", 3))
		bi_cd(sh, args, envp);
	else if (!ft_strncmp(*args, "pwd", 4))
		bi_pwd(sh, args, *envp);
	else if (!ft_strncmp(*args, "env", 4))
		bi_env(sh, args, envp);
	else if (!ft_strncmp(*args, "unset", 6))
		bi_unset(sh, args, envp);
	else if (!ft_strncmp(*args, "export", 7))
		bi_export(sh, args, envp);
	else if (!ft_strncmp(*args, "exit", 5))
		bi_exit(sh, args);
	else
		return (0);
	return (1);
}
