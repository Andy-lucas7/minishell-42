/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-do <jreis-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:30:13 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/03 19:09:44 by jreis-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_env(char *arg, char **envp)
{
	int	aux;
	char	*temp;

	if (!arg || !envp)
		return ;
	aux = 0;
	temp = ft_strjoin(arg, "=");
	while (envp[aux] && ft_strncmp(envp[aux], temp, ft_strlen(temp)))
		aux++;
	if (envp && envp[aux])
	{
		envp[aux] = free_ptr(envp[aux]);
		envp[aux] = envp[aux + 1];
		aux++;
		while (envp[aux])
		{
			envp[aux] = envp[aux + 1];
			aux++;
		}
		envp[aux] = NULL;
	}
	temp = free_ptr(temp);
}

void	bi_unset(t_mini *sh, char **args, char ***envp)
{
	while (*(++args))
		remove_env(*args, *envp);
	sh->error = 0;
}