/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:33:33 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/05 15:51:54 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*s;

	if (dest == NULL || src == NULL)
		return (dest);
	tmp = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest <= src)
	{
		while (n--)
			*tmp++ = *s++;
	}
	else
	{
		tmp += n;
		s += n;
		while (n--)
		{
			tmp--;
			s--;
			*tmp = *s;
		}
	}
	return (dest);
}
