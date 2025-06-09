/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:51:54 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/16 05:10:09 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	run_scmd(char **cmd, char **envp, t_mini *ms)
{
	char			*path;
	char			*error;
	int				i;

	i = 3;
	while (!close(i))
		i++;
	path = find_path(cmd[0], envp);
	if (!path)
	{
		error = ft_strjoin(PROMPT_MSG, cmd[0]);
		ft_putstr_fd(error, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		ms->error = 127;
		error = free_ptr (error);
		return ;
	}
	execve(path, cmd, envp);
	path = free_ptr(path);
	error = ft_strjoin(PROMPT_MSG": ", cmd[0]);
	perror(error);
	error = free_ptr(error);
}

static void	exit_child(t_mini *ms, char **cmd, int **fd, int code)
{
	int	i;

	ms->error = code;
	ms->input = free_ptr(ms->input);
	ms->prompt = free_ptr(ms->prompt);
	ms->token = free_token(ms->token);
	ms->envp = free_mat(ms->envp);
	cmd = free_mat(cmd);
	i = -1;
	if (fd)
	{
		while (fd[++i])
			fd[i] = (int *) free_ptr((char *) fd[i]);
		fd = (int **) free_mat((char **) fd);
	}
	rl_clear_history();
	unlink("__heredoc");
	exit(ms->error);
}

static void	file_error_message(t_mini *ms, char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ms->error = 1;
}

void	handle_invalid_file(t_mini *ms)
{
	t_token	*temp;

	temp = ms->token;
	while (temp)
	{
		if (temp->type == HEREDOC)
			ms->error = 0;
		if (temp->type == ARG_FILE)
		{
			if (access(temp->cmd, F_OK))
			{
				file_error_message(ms, temp->cmd);
				ft_putstr_fd(": No such file or directory\n", 2);
			}
			else if (access(temp->cmd, R_OK) || access(temp->cmd, W_OK))
			{
				file_error_message(ms, temp->cmd);
				ft_putstr_fd(": Permission Denied\n", 2);
				ms->error = 1;
			}
		}
		temp = temp->next;
	}
}

void	child(t_mini *ms, char **cmd, int **fd, int i)
{
	int	out;
	int	in;

	out = 0;
	in = 0;
	cmd = redirect(ms, cmd, &out, &in);
	if (!cmd || *cmd == NULL)
	{
		handle_invalid_file(ms);
		free_mat(cmd);
		exit_child(ms, NULL, fd, ms->error);
	}
	if (i && !in)
		dup2(fd[i - 1][0], 0);
	if (fd[i] && !out)
		dup2(fd[i][1], 1);
	close_fds(fd);
	run_scmd(cmd, ms->envp, ms);
	exit_child(ms, cmd, fd, ms -> error);
}
