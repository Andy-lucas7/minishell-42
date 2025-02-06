/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-do <jreis-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:02:38 by jreis-do          #+#    #+#             */
/*   Updated: 2025/02/05 21:01:15 by jreis-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_var_pos(char *var, char **envp)
{
	char	*var_temp;
	int		var_len;
	int		var_pos;

	var_len = ft_strchr (var, '=') - var;
	var_pos = 0;
	var_temp = ft_calloc (var_len + 2, sizeof (char));
	ft_strlcpy (var_temp, var, var_len + 2);
	var_temp[var_len] = '=';
	var_temp[var_len + 1] = '\0';
	while (envp[var_pos] && ft_strncmp (envp[var_pos], var_temp, var_len + 1))
		var_pos++;
	var_temp = free_ptr (var_temp);
	return (var_pos);
}

static void	update_var(char *var, int var_pos, char ***envp)
{
	char	**envp_temp;

	if (!envp[0][var_pos])
	{
		envp_temp = ft_calloc (var_pos + 2, sizeof (char *));
		envp_temp[var_pos] = ft_strdup (var);
		while (var_pos--)
			envp_temp[var_pos] = ft_strdup (envp[0][var_pos]);
		*envp = free_mat (*envp);
		*envp = envp_temp;
	}
	else
	{
		envp[0][var_pos] = free_ptr (envp[0][var_pos]);
		envp[0][var_pos] = ft_strdup (var);
	}
}

static void	update_env(char *env, int pos, char **envp)
{
	char	**temp;

	if (!envp[pos])
	{
		temp = ft_calloc(pos + 2, sizeof(char *));
	}
}

static int	validate_env(char *env)
{
	int	count;
	int	aux;

	aux = 1;
	if (!env || (env && env[0] == '=') || ft_isdigit(env[0]))
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
	if (!args[1])
		bi_env(sh, args, envp);
	while (args[count])
	{
		if (validate_env(args[count]) && ft_strchr(args[count], '='))
		{
			aux = env_pos(args[count], *envp);
			update_env(args[count], aux, *envp);
			sh->error = 0;
		}
		else if (!validate_env(args[count]))
		{
			ft_putstr_fd("export: not valid in this context: ", 2);
			ft_putstr_fd(args[count], 2);
			sh->error = 42;
		}
		else
			sh->error = 0;
		count++;
	}
}