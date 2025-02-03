#include "minishell.h"

void	bi_pwd(t_mini *ms, char **args, char **envp)
{
	int	count;

	if (!args[1])
	{
		count = 0;
		while (envp && !ft_strncmp(envp[count], "PWD=", 4))
			count++;
		if (envp && envp[count])
			printf("%s\n", envp[count] + 4);
	}
	else
	{
		ft_putstr_fd("-minishell: pwd: invalid usage", 2);
		ms->error = 42;
	}
}