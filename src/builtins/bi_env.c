/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:16:40 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/10 17:34:20 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_env(t_mini *ms, char **args, char ***envp)
{
	int	count;

	if (args[1])
	{
		ft_putstr_fd("-minishell: env: invalid usage\n", 2);
		ms->error = 42;
	}
	if (!strcmp(args[0], ))
	else
	{
		count = 0;
		while (envp && *envp && envp[0][count])
		{
			printf("%s\n", envp[0][count]);
			count++;
		}
		ms->error = 0;
	}
}
