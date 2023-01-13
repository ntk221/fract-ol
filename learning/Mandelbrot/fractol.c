/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:51:01 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/13 10:51:14 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"

int	mandelbrot(t_complex c, int maxiter)
{
	t_complex	z;

	z.re = 0.0;
	z.im = 0.0;
	for(int i = 0; i < maxiter; i++)
	{
		z = c_sum(c_mul(z, z), c);

		if (c_abs(z) > 4.0)
			return i;
	}
	return maxiter;
}
