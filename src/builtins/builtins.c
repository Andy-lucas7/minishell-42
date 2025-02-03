#include "minishell.h"

int	builtins(t_minishell *sh, char ***envp, char **args)
{
	if (!args || !*args || !*envp)
		return (-1);
	else if (!ft_strncmp(*args, "echo", 4))
		return (bi_echo(sh, args));
	else if (!ft_strncmp(*args, "cd", 2))
		return (bi_cd(sh, args, envp));
	else if (!ft_strncmp(*args, "pwd", 3))
		return (bi_pwd(sh, args, *envp));
	else if (!ft_strncmp(*args, "env", 3))
		return (bi_env(sh, args, envp));
	else if (!ft_strncmp(*args, "unset", 5))
		return (bi_unset(sh, args, envp));
	else if (!ft_strncmp(*args, "export", 6))
		return (bi_export(sh, args, envp));
	else if (!ft_strncmp(*args, "exit", 4))
		return (bi_exit(sh, args));
	else
		return (0);
	return (1);
}
