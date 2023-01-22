/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:40:24 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/15 12:04:19 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

static int	ft_abs(int x)
{
	if (x < 0)
		return (x *= -1);
	return (x);
}

char	*ft_itoa(int nbr)
{
	char	*buf;
	int		len;

	len = get_len(nbr);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	buf[len] = '\0';
	if (nbr < 0)
		buf[0] = '-';
	else if (nbr == 0)
		buf[0] = '0';
	while (nbr != 0)
	{
		len--;
		buf[len] = ft_abs(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (buf);
}
