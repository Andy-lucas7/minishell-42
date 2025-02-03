#include "minishell.h"

void	bi_echo(t_mini *sh, char **args)
{
	int	count;
	int	aux;
	int	nl;

	count = 1;
	nl = 1;
	while (args && args[count] && !ft_strncmp(args[count], "-n", 2))
	{
		aux = 2;
		while (args[count][aux] == 'n')
			aux++;
		if (args[count][aux] != '\0')
			break;
		count++;
		nl = 0;
	}
	while (args && args[count])
	{
		printf("%s", args[count]);
		if (args[++count])
			printf(" ");
	}
	if (nl)
		printf("\n");
	sh->error = 0;
}