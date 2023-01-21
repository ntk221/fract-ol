/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:14:03 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/15 11:32:42 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (n > 1 && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				break ;
			i++;
			n--;
		}
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
