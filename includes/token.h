/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:34:59 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/20 11:45:21 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "../lib/libft/libft.h"
# include "minishell.h"


enum e_numerator	get_token_type(char *str);
t_token				*create_token(char *value, enum e_numerator type);
void				add_token(t_minishell *shell, \
	char *value, enum e_numerator type);
void				tokenizer(t_minishell *shell);

#endif