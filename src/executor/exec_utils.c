/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:51:55 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/11 11:19:54 by lserrao-         ###   ########.fr       */
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
	while (fd[i])
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}
char    **change_matriz(char **mat, char *str)
{
    char    **new_mat;

    new_mat = ft_calloc(3, sizeof(char *));
    if (!new_mat)
        return (NULL);
    new_mat[0] = ft_strdup(str);
    if (mat && mat[0])
        new_mat[1] = ft_strdup(mat[0]);
    new_mat[2] = NULL;
    return (new_mat);
}
char	**change_matriz(char **mat, char *str)
{
	char	**new_mat;

	new_mat = ft_calloc(3, sizeof(char *));
	if (!new_mat)
		return (NULL);
	new_mat[0] = ft_strdup(str);
	if (mat && mat[0])
		new_mat[1] = ft_strdup(mat[0]);
	new_mat[2] = NULL;
	return (new_mat);
}
