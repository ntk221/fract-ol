/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:30:25 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/22 04:00:24 by knitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*uc_src;
	unsigned char	*uc_dest;
	size_t			i;

	if (dest == NULL)
		return (NULL);
	uc_src = (unsigned char *)src;
	uc_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		uc_dest[i] = uc_src[i];
		i++;
	}
	return (dest);
}
