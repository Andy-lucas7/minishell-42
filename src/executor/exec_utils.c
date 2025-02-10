/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:51:55 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/10 12:24:48 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**token_to_mat(t_token *token)
{
	int		i;
	int		j;
	char	**ret;
	t_token	*temp;

	temp = token;
	i = 0;
	while (temp && temp->type != PIPE)
	{
		i++;
		temp = temp->next;
	}
	ret = ft_calloc((i + 1), sizeof(char *));
	if (!ret)
		return (NULL);
	j = -1;
	while (++j < i)
	{
		ret[j] = ft_strdup(token->cmd);
		token = token->next;
	}
	ret[j] = NULL;
	return (ret);
}

void	close_fds(int **fd)
{
	int	i;

	i = 0;
	if (!fd)
		return ;
	while (fd[i])
	{
		if (fd[i][0] > 2)
			close(fd[i][0]);
		if (fd[i][1] > 2)
			close(fd[i][1]);
		i++;
	}
}
