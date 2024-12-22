/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:44:13 by lserrao-          #+#    #+#             */
/*   Updated: 2024/10/17 19:27:44 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest[dest_len] && dest_len < destsize)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dest_len == destsize)
		return (destsize + src_len);
	while (src[i] && (dest_len + i + 1) < destsize)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < destsize)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
