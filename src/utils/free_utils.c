/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-do <jreis-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:49:21 by lserrao-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/04 15:21:12 by lserrao-         ###   ########.fr       */
=======
/*   Updated: 2025/02/03 18:14:48 by jreis-do         ###   ########.fr       */
>>>>>>> bc0e4c7f17adc4189e8488fe3c36667323cb0643
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*free_ptr(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char	**free_mat(char **mat)
{
	size_t	i;

	i = 0;
	while (mat && mat[i])
	{
		mat[i] = free_ptr(mat[i]);
		i++;
	}
<<<<<<< HEAD
	free (mat);
	mat = NULL;
	return (NULL);
}

t_token	*free_token(t_token *token)
{
	t_token	*temp;

	while (token)
	{
		temp = token;
		token -> cmd = free_ptr (token -> cmd);
		token = token -> next;
		free (temp);
	}
	return (NULL);
}
=======
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
>>>>>>> bc0e4c7f17adc4189e8488fe3c36667323cb0643
