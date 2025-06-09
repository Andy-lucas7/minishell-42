/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:34:59 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/16 15:19:58 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	exit_handler(t_mini *ms, const char *msg, const int code);
int		check_quotes(char c, int quotes);
char	*ft_mattstr_copy(char **mat);
char	*free_ptr(char *ptr);
char	**free_mat(char **mat);
t_token	*free_token(t_token *token);
char	**lexer(char *input);
int		is_directory(t_mini *ms, char *cmd);
char	**ft_matdup(char **mat);
int		parser(t_token **head, char *str);
char	*find_path(char	*cmd, char **envp);
void	check_pipe(char *cmd, t_token **head);
int		syntax_checker(t_mini *ms);
char	*expand(t_mini *ms, char *cmd, char **envp);
void	expander(t_mini *ms, t_token **head, char **envp);
char	*get_envp(t_mini *ms, char *cmd, char **envp);
void	executor(t_mini *ms);
void	handle_invalid_file(t_mini *ms);
char	**token_to_mat(t_token *token);
void	close_fds(int **fd);
void	child(t_mini *ms, char **cmd, int **fd, int i);
char	**redirect(t_mini *ms, char **cmd, int *out, int *in);
void	set_redirect(t_mini *ms, char **cmd, int *fd, char **ret);
void	free_fd(int **fd);
int		builtins(t_mini *sh, char ***envp, char **args, int **fd);
void	bi_unset(t_mini *sh, char **args, char ***envp);
void	bi_pwd(t_mini *ms, char **args, char **envp);
void	bi_env(t_mini *ms, char **args, char ***envp);
void	bi_cd(t_mini *sh, char **args, char ***envp);
void	bi_export(t_mini *sh, char **args, char ***envp);
void	bi_exit(t_mini *sh, char **args);
void	bi_echo(t_mini *sh, char **args);

#endif