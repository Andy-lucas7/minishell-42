/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:40:41 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/07 17:57:19 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_num(char *str)
{
	int	count;

	count = 0;
	while (str && str[count])
	{
		if (!(ft_isdigit(str[count]) || str[count] == '+'))
			return (0);
		count++;
	}
	return (1);
}

static int	find_zero(char *args)
{
	int	count;

	count = 0;
	while (args[count])
	{
		if (args[count] != '0')
			return (1);
		count++;
	}
	return (0);
}

void	bi_exit(t_mini *sh, char **args)
{
	int	num;

	if (!args[1] || !find_zero(args[1]))
	{
		args = free_mat(args);
		exit_handler(sh, NULL, 0);
	}
	if (!args[2] && valid_num(args[1]))
	{
		num = ft_atoi(args[1]);
		exit_handler(sh, "exited with error number", num);
	}
	exit_handler(sh, "-SHELL-E: exit: invalid usage\n", 42);
	args = free_mat(args);
}
