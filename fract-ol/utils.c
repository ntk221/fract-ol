/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:03:32 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 03:24:36 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include "include/libft.h"

void	die(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

void	print_usage(void)
{
	ft_putendl_fd("Usage:", 2);
	ft_putendl_fd("\nYou can select two fractals", 2);
	ft_putendl_fd("\n\tm  Mandelbrot Set", 2);
	ft_putendl_fd("\tj  Julia Set", 2);
	ft_putendl_fd("\nIf, you select Julia, you can select number 0-2", 2);
	ft_putendl_fd("\nexample:\t", 2);
	ft_putendl_fd("\t./fractol J 0\n", 2);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->line_length + x * (fractol->bits / 8));
	*(unsigned int *)dst = color;
}
