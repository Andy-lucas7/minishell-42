/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:51:00 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/20 11:39:04 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/token.h"

// void	tokenizer(t_minishell *shell);


    // catalogo de tokens

	// if (ft_isspace(c[*i]) == 1)
	// 	return (SSPACE);
	// else if (!ft_strnchr(&c[*i], '<', 2))
	// 	return (HEREDOC);
	// else if (!ft_strnchr(&c[*i], '>', 2))
	// 	return (APPEND);
	// else if (!ft_strnchr(&c[*i], '|', 2))
	// 	return (OR);
	// else if (!ft_strnchr(&c[*i], '<', 1))
	// 	return (INPUT);
	// else if (!ft_strnchr(&c[*i], '>', 1))
	// 	return (OUTPUT);
	// else if (!ft_strnchr(&c[*i], '|', 1))
	// 	return (PIPE);
	// else if (!ft_strnchr(&c[*i], '"', 1))
	// 	return (DOUBLE);
	// else if (!ft_strnchr(&c[*i], '\'', 1))
	// 	return (SIMPLE);
	// else
	// 	return (WORD);

enum e_numerator	get_token_type(char *str)
{
	if (isspace(*str))
		return (SSPACE);
	else if (!!ft_strncmp(str, "<<", 2))
		return (HEREDOC);
	else if (!ft_strncmp(str, ">>", 2))
		return (APPEND);
	else if (!ft_strncmp(str, "||", 2))
		return (OR);
	else if (!ft_strncmp(str, "<", 1))
		return (INPUT);
	else if (!ft_strncmp(str, ">", 1))
		return (OUTPUT);
	else if (!ft_strncmp(str, "|", 1))
		return (PIPE);
	else if (!ft_strncmp(str, "\"", 1))
		return (DOUBLE);
	else if (!ft_strncmp(str, "\'", 1))
		return (SIMPLE);
	else
		return (WORD);
}

void	add_token(t_minishell *shell, char *value, enum e_numerator type)
{
	t_token	*new_token;
	t_token	*current;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return ;
	new_token->value = ft_strdup(value);
	new_token->type = type;
	new_token->next = NULL;
	if (!shell->tokens)
		shell->tokens = new_token;
	else
	{
		current = shell->tokens;
		while (current->next)
			current = current->next;
		current->next = new_token;
	}
}

void	tokenizer(t_minishell *shell)
{
	char	*ptr;
	char	token[256];
	int		i;

	ptr = shell->input;
	while (*ptr)
	{
		i = 0;
		if (isspace(*ptr))
			ptr++;
		else if (*ptr == '|' || *ptr == '<' || *ptr == '>')
		{
			token[i++] = *ptr++;
			if ((*ptr == '>' && token[0] == '>') || (*ptr == '<' && token[0] == '<'))
				token[i++] = *ptr++;
			token[i] = '\0';
			add_token(shell, token, get_token_type(token));
		}
		else
		{
			while (*ptr && !isspace(*ptr) && *ptr != '|' && *ptr != '<' && *ptr != '>')
				token[i++] = *ptr++;
			token[i] = '\0';
			add_token(shell, token, WORD);
		}
	}
}
