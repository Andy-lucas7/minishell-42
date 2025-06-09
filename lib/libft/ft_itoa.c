/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:09:57 by lserrao-          #+#    #+#             */
/*   Updated: 2025/02/05 17:54:12 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	int		temp;

	temp = n;
	if (!temp)
		return (ft_strdup("0"));
	i = 0;
	while (temp)
	{
		temp = temp / 10;
		i++;
	}
	num = ft_calloc(i + 1, sizeof(char));
	while (n)
	{
		num[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (num);
}
