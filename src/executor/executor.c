/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:38 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/16 20:05:53 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_executor	init_executor(t_mini *ms)
{
	int			i;
	t_executor	ex;

	ex.pid = 0;
	ex.status = 0;
	ex.n_pros = 1;
	ex.temp = ms->token;
	ex.cmd = token_to_mat(ex.temp);
	while (ex.temp)
	{
		if (ex.temp->type == PIPE)
			ex.n_pros++;
		ex.temp = ex.temp->next;
	}
	ex.fd = ft_calloc(ex.n_pros, sizeof(int *));
	i = -1;
	while (++i < (ex.n_pros - 1))
		ex.fd[i] = ft_calloc(2, sizeof(int));
	i = -1;
	while (++i < (ex.n_pros - 1))
		pipe(ex.fd[i]);
	ex.temp = ms->token;
	return (ex);
}

static int	exec_on_parent(t_mini *ms, int n_pros, char **cmd, int **fd)
{
	char	*full_path;
	int		j;

	j = -1;
	if (n_pros > 1)
		return (-1);
	full_path = find_path(cmd[0], ms->envp);
	if (!strncmp(cmd[0], "./", 2))
		return (-1);
	if (n_pros == 1 && full_path)
	{
		if (!(cmd[0][0] == '/'))
			free(full_path);
		return (-1);
	}
	if (builtins(ms, &ms->envp, cmd, fd))
		return (0);
	if (!full_path)
	{
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		ms->error = 127;
		return (free(full_path), 0);
	}
	return (-1);
}

static void	exec_on_child(t_mini *ms, t_executor *ex, int i)
{
	ex->pid = malloc(sizeof(pid_t) * ex->n_pros);
	while (++i < ex->n_pros)
	{
		if (i)
			ex->cmd = token_to_mat(ex->temp);
		ex->pid[i] = fork();
		if (ex->pid[i] == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			child(ms, ex->cmd, ex->fd, i);
		}
		while (ex->temp && ex->temp->type != PIPE)
			ex->temp = ex->temp->next;
		if (ex->temp && ex->temp->type == PIPE)
			ex->temp = ex->temp->next;
		ex->cmd = free_mat(ex->cmd);
	}
}

void	executor(t_mini *ms)
{
	int			i;
	int			j;
	t_executor	ex;

	if (!ms->token || !ms->token->cmd || !*ms->token->cmd)
		return ;
	ex = init_executor(ms);
	i = exec_on_parent(ms, ex.n_pros, ex.cmd, ex.fd);
	j = -1;
	if (i == 0)
	{
		free_mat(ex.cmd);
		return ;
	}
	exec_on_child(ms, &ex, i);
	close_fds(ex.fd);
	while (ex.fd[++j])
		ex.fd[j] = (int *) free_ptr((char *) ex.fd[j]);
	ex.fd = (int **) free_mat((char **) ex.fd);
	j = -1;
	while (++j < ex.n_pros)
		waitpid(ex.pid[j], &ex.status, 0);
	if (WIFEXITED(ex.status) && i != ex.n_pros)
		ms->error = WEXITSTATUS(ex.status);
	free(ex.pid);
}
