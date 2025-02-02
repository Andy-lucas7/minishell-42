/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:27:03 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/22 11:32:20 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H
# include "../lib/libft/libft.h"
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

char	*join_path(const char *dir, const char *cmd);
void	free_paths(char **paths);
char	*get_path_env(char **envp);
char	**get_paths(const char *path_env);
char	*find_command(const char *cmd, char **envp);
void	execute_command(char **args, char **envp);

#endif