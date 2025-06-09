/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:18:42 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/16 05:08:06 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_pipe(char *cmd, t_token **head)
{
	char				*input;

	input = NULL;
	if (!ft_strncmp(cmd, "|", 2))
	{
		input = readline("> ");
		if (input && !input[0])
		{
			input = free_ptr(input);
			return ;
		}
		if (!input)
		{
			ft_putendl_fd(PROMPT_MSG"syntax error: unexpected end of file", 2);
			ft_putendl_fd("exit\n", 2);
			exit(2);
		}
		parser(head, input);
		input = free_ptr(input);
	}
}
