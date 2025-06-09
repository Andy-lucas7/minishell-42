/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:04:22 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/13 15:46:50 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_next(t_mini *ms, t_token *token, int type)
{
	if (type == PIPE && token->next && token->next->type == PIPE)
	{
		printf(PROMPT_MSG"syntax error near unexpected token %s\n", \
		token->next->cmd);
		ms->error = 2;
		return (2);
	}
	else if ((type == REDIRECT && token->next == NULL) || \
	(type == REDIRECT && (token->next->type == PIPE || \
	token->next->type == REDIRECT || token->next->type == HEREDOC)))
	{
		printf(PROMPT_MSG"syntax error near unexpected token %s\n", \
		token->cmd);
		ms->error = 2;
		return (2);
	}
	return (0);
}

int	syntax_checker(t_mini *ms)
{
	t_token	*temp;

	temp = ms->token;
	while (temp)
	{
		if (temp->type == PIPE)
		{
			if (check_next(ms, temp, PIPE))
				return (2);
		}
		else if (temp->type == REDIRECT)
		{
			if (check_next(ms, temp, REDIRECT))
				return (2);
		}
		else if (ft_strchr(temp->cmd, '\\'))
		{
			printf(PROMPT_MSG"syntax error, token `\\' is not accepted\n");
			ms->error = 2;
			return (2);
		}
		temp = temp->next;
	}
	return (0);
}
