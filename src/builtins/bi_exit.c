/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:40:41 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/16 16:00:04 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_num(char *str)
{
	int	count;

	count = 0;
	while (str && str[count])
	{
		if (!(ft_isdigit(str[count]) || str[count] == '+' \
			|| str[count] == '-'))
			return (0);
		count++;
	}
	return (1);
}

static int	find_zero(char *args)
{
	int	count;

	count = -1;
	while (args[++count])
	{
		if (args[count] != '0')
			return (1);
	}
	return (0);
}

static void	exit_aux(t_mini *sh, char **args)
{
	args = free_mat(args);
	exit_handler(sh, NULL, 0);
}

static int	count_mat(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

void	bi_exit(t_mini *sh, char **args)
{
	int	num;
	int	num_args;

	num_args = count_mat(args);
	if (num_args > 2)
	{
		ft_putstr_fd(PROMPT_MSG"exit: excessive number of arguments\n", 2);
		sh->error = 1;
		return ;
	}
	if (!args[1])
		exit_aux(sh, args);
	if (!find_zero(args[1]))
		exit_aux(sh, args);
	if (!args[2] && valid_num(args[1]))
	{
		num = ft_atoi(args[1]);
		args = free_mat(args);
		exit_handler(sh, "exited with error number", num);
	}
	else
	{
		args = free_mat(args);
		exit_handler(sh, PROMPT_MSG": exit: invalid usage\n", 2);
	}
}
