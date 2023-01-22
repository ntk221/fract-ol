/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:55:40 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/16 00:27:07 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char		*substr;
	char const	*s;
	size_t		i;
	size_t		sub_len;

	s = src;
	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(src) < start)
		return (ft_strdup(""));
	sub_len = ft_strlen(src + start);
	if (sub_len < len)
		len = sub_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	s += start;
	i = 0;
	while (*s != '\0' && len-- != 0)
	{
		substr[i++] = *s;
		s++;
	}
	substr[i] = '\0';
	return (substr);
}
