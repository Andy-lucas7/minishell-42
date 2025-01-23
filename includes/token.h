/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:34:59 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/21 15:31:47 by lserrao-         ###   ########.fr       */
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
char				**tokenize_input(char *input);
void				free_tokens(t_token *tokens);
char				**convert_tokens_to_args(t_token *tokens);

#endif