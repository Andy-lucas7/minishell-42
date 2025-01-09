/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:46:53 by lserrao-          #+#    #+#             */
/*   Updated: 2025/01/09 18:20:28 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// pesquisar sobre parsing
// pesquisar sobre tokenização

static char	*prompt(char *argm, char **envar)
{
	char	*input;

	while (1)
	{
		input = readline("\033[0;36mMinishell: \033[0m");
		execve("PATH", argm, **envar);
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break ;
		}
		if (*input)
			add_history(input);
		free(input);
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envar)
{
	char	*input;

	while (1)
	{
		input = prompt(argv[1], **envar);
		if (input == NULL)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
