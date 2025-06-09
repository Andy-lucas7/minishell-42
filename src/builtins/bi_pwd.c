/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:16:35 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/16 06:21:40 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_pwd(t_mini *ms, char **args, char **envp)
{
	int	count;

	if (args[0])
	{
		count = 0;
		while (envp && ft_strncmp(envp[count], "PWD=", 4))
			count++;
		if (envp && envp[count])
			printf("%s\n", envp[count] + 4);
	}
	else
	{
		ft_putstr_fd(PROMPT_MSG"pwd: invalid usage\n", 2);
		ms->error = 42;
	}
}
