/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:46:53 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/16 14:35:11 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_input(t_mini *ms, const char *prompt)
{
	char	*input;

	input = readline(prompt);
	if (input && input[0])
		add_history(input);
	else if (!input)
		exit_handler (ms, EXIT_MSG, 0);
	return (input);
}

static void	cleaner(t_mini *ms)
{
	ms->input = free_ptr(ms->input);
	ms->token = free_token(ms->token);
	unlink("__heredoc");
}

static void	ft_sa_handler(int sig, siginfo_t *info, void *context)
{
	(void) context;
	printf("\n");
	if (sig == SIGINT && info->si_pid)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static t_mini	ft_init(int argc, char **argv, char **envp)
{
	t_mini				ms;
	struct sigaction	sa;

	(void) argv;
	ft_bzero(&ms, sizeof(t_mini));
	if (argc > 1)
		exit_handler(&ms, "Usage: ./minishell", 1);
	ft_bzero (&sa, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_sa_handler;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	ms.envp = ft_matdup(envp);
	if (!envp)
		exit_handler(&ms, "Can't allocate memory to environment variables", 1);
	ms.prompt = ft_strdup("\001\033[1;32m\002SHELL\001\033[1;37m\002-E: \
\001\033[0m\002");
	if (!ms.prompt)
		exit_handler(&ms, "Can't allocate memory to prompt name", 1);
	return (ms);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	ms;

	ms = ft_init(argc, argv, envp);
	while (1)
	{
		ms.input = get_input (&ms, ms.prompt);
		if (ms.input && *ms.input)
		{
			if (!parser(&ms.token, ms.input) && !syntax_checker(&ms))
			{
				expander(&ms, &ms.token, ms.envp);
				executor(&ms);
			}
		}
		cleaner(&ms);
	}
	return (0);
}
