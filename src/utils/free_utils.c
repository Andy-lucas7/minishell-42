/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-do <jreis-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:49:21 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/03 18:14:48 by jreis-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Libera memória de uma lista de strings
void	free_paths(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	*free_ptr(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char	**free_mat(char **mat)
{
	int	count;

	count = 0;
	while (mat && mat[count])
	{
		mat[count] = free_ptr(mat[count]);
		count++;
	}
	free(mat);
	mat = NULL;
	return (NULL);
}