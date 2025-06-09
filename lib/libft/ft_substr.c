/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:35:05 by lserrao-          #+#    #+#             */
/*   Updated: 2024/10/31 19:19:12 by lserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	finish;

	if (!s)
		return (0);
	slen = ft_strlen((char *)s);
	finish = 0;
	if (start >= slen)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (start < slen)
		finish = slen - start;
	if (finish > len)
		finish = len;
	new = (char *)ft_calloc(sizeof(char), (finish + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, finish + 1);
	return (new);
}
