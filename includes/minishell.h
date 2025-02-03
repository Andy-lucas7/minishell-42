/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:27:03 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/03 17:30:15 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H
# include "../lib/libft/libft.h"
# include "structs.h"
# include "defines.h"
# include "functions.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>


char	*join_path(const char *dir, const char *cmd);
void	free_paths(char **paths);
char	*get_path_env(char **envp);
char	**get_paths(const char *path_env);
char	*find_command(const char *cmd, char **envp);
void	execute_command(char **args, char **envp);

#endif