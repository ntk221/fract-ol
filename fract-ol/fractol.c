/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:51:01 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/21 22:47:11 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"

int	mandelbrot(t_complex c, int maxiter)
{
	t_complex	z;
	int			i;

	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while (i < maxiter)
	{
		z = c_sum(c_mul(z, z), c);
		if (c_abs(z) > 4.0)
			return (i);
		i++;
	}
	return (maxiter);
}

int	julia(t_complex z, t_complex c, int maxiter)
{
	int	i;

	i = 0;
	while (i < maxiter)
	{
		z = c_sum(c_mul(z, z), c);
		if (c_abs(z) > 4.0)
			return (i);
		i++;
	}
	return (maxiter);
}
