/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-do <jreis-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:16:35 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/10 18:03:11 by jreis-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_pwd(t_mini *ms, char **args, char **envp)
{
	int	count;

	if (!args[1])
	{
		count = 0;
		while (envp && ft_strncmp(envp[count], "PWD=", 4))
			count++;
		if (envp && envp[count])
			printf("%s\n", envp[count] + 4);
	}
	else if (args[1])
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		ms->error = 1;
	}
	else
	{
		ft_putstr_fd("-minishell: pwd: invalid usage\n", 2);
		ms->error = 42;
	}
}
