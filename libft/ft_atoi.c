/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:05:54 by kazuki            #+#    #+#             */
/*   Updated: 2022/10/10 23:23:53 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	num;
	long long int	n;

	sign = 1;
	num = 0;
	while (*str != '\0' && is_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = num;
		num = num * 10 + sign * (*str++ - '0');
		if (num > n && sign == -1)
			return (0);
		if (num < n && sign == 1)
			return (-1);
	}
	return (num);
}
