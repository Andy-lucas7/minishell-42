/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:50:19 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/16 16:32:56 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*set_right_path(char *cmd, char **paths)
{
	int		i;
	char	*ret;
	char	*temp;

	i = -1;
	ret = NULL;
	while (paths && paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		ret = ft_strjoin(temp, cmd);
		temp = free_ptr(temp);
		if ((!access(ret, F_OK)) && !access(ret, X_OK))
			break ;
		ret = free_ptr(ret);
	}
	return (ret);
}

char	*find_path(char	*cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*rigth_path;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if ((!access(cmd, F_OK)) && !access(cmd, X_OK) \
		&& ft_strlen(cmd) > 2)
			return (cmd);
		return (NULL);
	}
	i = -1;
	while (envp && envp[++i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
			break ;
	}
	if (envp[i] == NULL)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	rigth_path = set_right_path(cmd, paths);
	paths = free_mat(paths);
	return (rigth_path);
}
