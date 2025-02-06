/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:27:48 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/06 17:24:37 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifndef ERROR_MSG
#  define ERROR_MSG "\033[1;31mERROR\n\033[0m"
# endif

# ifndef EXIT_MSG
#  define EXIT_MSG "\n\033[1;37mSHELLin matador de porco diz: Até logo, \
humano.\033[0m"
# endif

# ifndef PROMPT_MSG
#  define PROMPT_MSG "\001\033[1;32mSHELL\001\033[1;37m\002-E: \001\033[0m\002"
# endif

# ifndef INVALID_USAGE
#  define INVALID_USAGE "invalid usage"
# endif

# ifndef SIZE
#  define SIZE 4096
# endif

# ifndef SEP
#  define SEP -1
# endif

enum e_type{
	PIPE = 10,
	EXECVE = 11,
	BUILDIN = 12,
	ARG = 13,
	ARG_FILE = 14,
	REDIRECT = 15,
	HEREDOC = 16
};

#endif