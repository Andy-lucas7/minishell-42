/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:24:32 by lserrao-          #+#    #+#             */
/*   Updated: 2024/10/18 19:38:43 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	value;
	unsigned char	*ptr;

	value = (unsigned char) c;
	ptr = (unsigned char *) s;
	while (n > 0)
	{
		if (*ptr == value)
			return ((void *) ptr);
		ptr++;
		n--;
	}
	if (!ptr)
		return (NULL);
	return (NULL);
}
