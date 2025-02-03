/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:46:53 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/03 17:25:07 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// // pesquisar sobre parsing
// // pesquisar sobre tokenização

// // Retorna a variável PATH do ambiente
// char	*get_path_env(char **envp)
// {
// 	int	i;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (strncmp(envp[i], "PATH=", 5) == 0)
// 			return (envp[i] + 5);
// 		i++;
// 	}
// 	return (NULL);
// }

// void	free_args(char **args)
// {
// 	int	i;

// 	i = 0;
// 	if (!args)
// 		return ;
// 	while (args[i])
// 		free(args[i++]);
// 	free(args);
// }

// static char	*prompt(char **envp)
// {
// 	t_minishell	shell;
// 	t_token		*current;
// 	char		**args;

// 	shell.input = NULL;
// 	while (1)
// 	{
// 		shell.input = readline("\001\033[1;32mSHELL\001\033[1;37m\002-E: \001\033[0m\002");
// 		if (!shell.input)
// 		{
// 			printf("exit\n");
// 			rl_clear_history();
// 			break ;
// 		}
// 		if (*shell.input)
// 		{
// 			add_history(shell.input);
// 			shell.tokens = NULL;
// 			tokenizer(&shell);
// 			current = shell.tokens;
// 			while (current)
// 				current = current->next;
// 			if (shell.tokens && shell.tokens->type == WORD)
// 			{
// 				args = convert_tokens_to_args(shell.tokens);
// 				execute_command(args, envp);
// 				free_args(args);
// 			}
// 			free_tokens(shell.tokens);
// 		}
// 		free(shell.input);
// 	}
// 	return (NULL);
// }

// // Função principal
// int	main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;
// 	signal(SIGQUIT, SIG_IGN);
// 	if (!isatty(STDIN_FILENO))
// 	{
// 		write(1, "Error:\nNot a terminal.\n", 23);
// 		return (EXIT_FAILURE);
// 	}
// 	prompt(envp);
// 	return (EXIT_SUCCESS);
// }

int	main(int argc, char **argv, char **envp)
{
	t_mini	ms;

	ms = ft_init(argc, argv, envp);
	
}
