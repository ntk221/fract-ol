/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:18:29 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/10 23:29:02 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lit_len;

	if (big == NULL || little == NULL)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	if (*big == '\0' || len == 0)
		return (NULL);
	lit_len = ft_strlen(little);
	if (lit_len == 0)
		return ((char *)big);
	while (lit_len <= len && *big != '\0')
	{
		if (*big == *little && (0 == ft_strncmp(big, little, lit_len)))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
