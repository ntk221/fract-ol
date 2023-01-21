/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:35:37 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/05 11:12:06 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*dest;

	dest = (char *)b;
	while (len > 0)
	{
		*dest = (char)c;
		len--;
		dest++;
	}
	return (b);
}
