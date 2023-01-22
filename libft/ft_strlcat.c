/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:34:59 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/15 01:45:44 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*s = src;
	size_t		dlen;
	size_t		n;

	if (dst == NULL)
		return (ft_strlen(src));
	n = dstsize;
	dlen = ft_strlen(dst);
	dst += dlen;
	n = dstsize - dlen;
	if (dstsize <= dlen)
		return (dstsize + ft_strlen(src));
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*dst++ = *s;
			n--;
		}
		s++;
	}
	*dst = '\0';
	return (dlen + (s - src));
}
