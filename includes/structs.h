/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:18:50 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/20 11:25:54 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


enum e_numerator
{
	SSPACE,
	PIPE,
	INPUT,
	OUTPUT,
	WORD,
	HEREDOC,
	APPEND,
	DOUBLE,
	SIMPLE,
	BLOCK,
	ARCHIVE,
	DELIMITER,
	REDIRECT,
	OR
};

typedef struct s_token
{
	char				*value;
	enum e_numerator	type;
	struct s_token		*next;
}	t_token;

typedef struct s_minishell
{
	int			status;
	char		*input;
	char		*complete_path;
	char		**env_copy;
	char		**paths;
	char		**cmd_args;
	t_token		*tokens;
}	t_minishell;