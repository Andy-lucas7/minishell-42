/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:18:42 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/14 20:47:00 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_pipe(char *cmd, t_token **head)
{
	char				*input;

	input = NULL;
	if (!ft_strncmp(cmd, "|", 2) || cmd[1] == '\0')
	{
		input = readline("> ");
		if (input && !input[0])
		{
			input = free_ptr(input);
			return ;
		}
		parser(head, input);
		input = free_ptr(input);
	}
}
