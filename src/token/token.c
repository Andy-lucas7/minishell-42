/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:51:00 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/17 12:16:45 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/token.h"

void	tokenizer(t_minishell *shell);


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