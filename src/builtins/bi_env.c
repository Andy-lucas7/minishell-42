#include "minishell.h"

void	bi_env(t_mini *ms, char **args, char ***envp)
{
	int	count;

	if (args[1])
	{
		ft_putstr_fd("-minishell: env: invalid usage\n",2);
		ms->error = 42;
	}
	else
	{
		count = 0;
		while (envp && *envp && envp[0][count])
		{
			printf("%s\n", envp[0][count]);
			count++;
		}
		ms->error = 0;
	}
}