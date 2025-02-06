/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-do <jreis-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:16:29 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/03 17:43:35 by jreis-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins(t_mini *sh, char ***envp, char **args)
{
	if (!args || !*args || !*envp)
		return (-1);
	else if (!ft_strncmp(*args, "echo", 4))
		bi_echo(sh, args);
	else if (!ft_strncmp(*args, "cd", 2))
		bi_cd(sh, args, envp);
	else if (!ft_strncmp(*args, "pwd", 3))
		bi_pwd(sh, args, *envp);
	else if (!ft_strncmp(*args, "env", 3))
		bi_env(sh, args, envp);
	else if (!ft_strncmp(*args, "unset", 5))
		bi_unset(sh, args, envp);
	else if (!ft_strncmp(*args, "export", 6))
		bi_export(sh, args, envp);
//	else if (!ft_strncmp(*args, "exit", 4))
//		return (bi_exit(sh, args));
	else
		return (0);
	return (1);
}
