/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:09:22 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/07 10:50:46 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strrev(char *str)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = ft_strlen(str);
	while (j > i)
	{
		j--;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		neg;
	char	*tmp;

	i = 0;
	neg = 0;
	tmp = malloc(sizeof(char) * 12);
	if (tmp == NULL || nbr == 0)
		return ((nbr == 0) ? "0" : NULL);
	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	while (nbr)
	{
		tmp[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg)
		tmp[i] = '-';
	return (ft_strrev(tmp));
}

int	main(int ac, char **av)
{
	char	*result;
	int		i;

	i = atoi(av[1]);
	(void)ac;
	result = ft_itoa(i);
	printf("%s", result);
	return (0);
}
