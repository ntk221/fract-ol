/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:10:48 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/16 00:28:42 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb != 0)
		if (SIZE_MAX / nmemb < size)
			return (NULL);
	mem = (void *)malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size * nmemb);
	return (mem);
}
