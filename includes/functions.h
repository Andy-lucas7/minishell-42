/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:34:59 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/04 15:26:37 by lserrao-         ###   ########.fr       */
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
int		parser(t_token **head, char *str);
char	*find_path(char	*cmd, char **envp);
void	check_pipe(char *cmd, t_token **head);
int		syntax_checker(t_mini *ms);
char	*expand(t_mini *ms, char *cmd, char **envp);
void	expander(t_mini *ms, t_token **head, char **envp);
char	*get_envp(t_mini *ms, char *cmd, char **envp);
void	executor(t_mini *ms);
char	**token_to_mat(t_token *token);
void	close_fds(int **fd);
void	child(t_mini *ms, char **cmd, int **fd, int i);
char	**redirect(t_mini *ms, char **cmd, int *out, int *in);
void	set_redirect(t_mini *ms, char **cmd, int *fd, char **ret);
int		execbi(t_mini *ms, char **cmd, char ***envp, char *prompt);
void	ft_echo(t_mini *ms, char **cmd);
void	ft_cd(t_mini *ms, char **cmd, char ***envp);
void	ft_pwd(t_mini *ms, char **cmd, char **envp);
void	ft_export(t_mini *ms, char **cmd, char ***envp);
void	ft_unset(t_mini *ms, char **cmd, char ***envp);
void	ft_env(t_mini *ms, char **cmd, char ***envp);
void	ft_exit(t_mini *ms, char **cmd);

#endif