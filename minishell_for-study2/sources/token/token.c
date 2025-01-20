/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:49:06 by bda-mota          #+#    #+#             */
/*   Updated: 2025/01/20 11:45:06 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	catalog_inputs(char *c, size_t *i)
{
	if (ft_isspace(c[*i]) == 1)
		return (SSPACE);
	else if (!ft_strnchr(&c[*i], '<', 2))
		return (HEREDOC);
	else if (!ft_strnchr(&c[*i], '>', 2))
		return (APPEND);
	else if (!ft_strnchr(&c[*i], '|', 2))
		return (OR);
	else if (!ft_strnchr(&c[*i], '<', 1))
		return (INPUT);
	else if (!ft_strnchr(&c[*i], '>', 1))
		return (OUTPUT);
	else if (!ft_strnchr(&c[*i], '|', 1))
		return (PIPE);
	else if (!ft_strnchr(&c[*i], '"', 1))
		return (DOUBLE);
	else if (!ft_strnchr(&c[*i], '\'', 1))
		return (SIMPLE);
	else
		return (WORD);
}

// Função para criar tokens
t_token	*create_token(char *value, enum e_numerator type)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->value = value;
	new_token->type = type;
	new_token->next = NULL;
	return (new_token);
}

void	tokenizer(t_minishell *shell)
{
	size_t	i;
	int		type;

	i = 0;
	if (!check_sintax(shell->input))
		return ;
	while (shell->input[i] && (i != ft_strlen(shell->input)))
	{
		type = catalog_inputs(shell->input, &i);
		if (type == WORD || type == DOUBLE || type == SIMPLE || type == OR)
			handle_word(&shell->token, shell->input, &i);
		else if (type == PIPE || type == INPUT || type == OUTPUT)
			handle_one(&shell->token, shell->input, &i);
		else if (type == HEREDOC || type == APPEND)
			handle_two(&shell->token, shell->input, &i);
		i++;
	}
}
