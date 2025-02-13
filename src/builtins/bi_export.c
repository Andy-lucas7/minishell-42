/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:02:38 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/12 23:23:36 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_pos(char *env, char **envp)
{
	char	*temp;
	int		count;
	int		aux;

	count = ft_strchr(env, '=') - env;
	aux = 0;
	temp = ft_calloc(count + 2, sizeof(char));
	ft_strlcpy(temp, env, count + 2);
	temp[count] = '=';
	temp[count + 1] = '\0';
	while (envp[aux] && ft_strncmp(envp[aux], temp, count + 1))
		aux++;
	temp = free_ptr(temp);
	return (aux);
}

static void	update_env(char *env, int pos, char ***envp)
{
	char	**temp;

	if (!envp[0][pos])
	{
		temp = ft_calloc(pos + 2, sizeof(char *));
		temp[pos] = ft_strdup(env);
		while (pos--)
			temp[pos] = ft_strdup(envp[0][pos]);
		*envp = free_mat(*envp);
		*envp = temp;
	}
	else
	{
		envp[0][pos] = free_ptr(envp[0][pos]);
		envp[0][pos] = ft_strdup(env);
	}
}

static int	validate_env(char *env)
{
	int	count;
	int	aux;

	aux = 1;
	if (!env || (env && env[0] == '='))
		aux = 0;
	if (ft_isdigit(env[0]))
		aux = 0;
	count = 0;
	while (env[count] && env[count] != '=')
	{
		if (env[count] != '_' && !ft_isalnum(env[count]))
			aux = 0;
		count++;
	}
	return (aux);
}

void	bi_export(t_mini *sh, char **args, char ***envp)
{
	int	count;
	int	aux;

	count = 1;
	if (!ft_strncmp(args[0], "export", 7) && !args[1])
		bi_env(sh, args, envp);
	while (args[count])
	{
		if (validate_env(args[count]) && ft_strchr(args[count], '='))
		{
			aux = env_pos(args[count], *envp);
			update_env(args[count], aux, envp);
			sh->error = 0;
		}
		else if (!validate_env(args[count]))
		{
			ft_putstr_fd(PROMPT_MSG"export: ", 2);
			ft_putstr_fd(args[count], 2);
			ft_putstr_fd(": not a valid identifier\n", 2);
			sh->error = 1;
		}
		else
			sh->error = 0;
		count++;
	}
}
