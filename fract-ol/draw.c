/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:28:35 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 03:28:48 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include "include/libft.h"

void	put_function(int value, t_fractol *fractol, int i, int j)
{
	if (value > 90)
		my_mlx_pixel_put(fractol, i, j, 0xE00000);
	else if (value > 70)
		my_mlx_pixel_put(fractol, i, j, 0x0E0000);
	else if (value > 50)
		my_mlx_pixel_put(fractol, i, j, 0xAA0000);
	else if (value > 30)
		my_mlx_pixel_put(fractol, i, j, 0x6E0000);
	else if (value > 10)
		my_mlx_pixel_put(fractol, i, j, 0x550000);
	else if (value > 5)
		my_mlx_pixel_put(fractol, i, j, 0x400000);
	else if (value > 4)
		my_mlx_pixel_put(fractol, i, j, 0x300000);
	else if (value > 3)
		my_mlx_pixel_put(fractol, i, j, 0x200000);
	else if (value > 2)
		my_mlx_pixel_put(fractol, i, j, 0x100000);
	else if (value > 1)
		my_mlx_pixel_put(fractol, i, j, 0x050000);
	else
		my_mlx_pixel_put(fractol, i, j, 0x000000);
}

void	render_mandelbrot(t_fractol *fractol)
{
	int			i;
	int			j;
	t_complex	c;
	int			value;

	fractol->dx = (fractol->x_fin - fractol->x_start) / (WIDTH);
	fractol->dy = (fractol->y_fin - fractol->y_start) / (HEIGHT);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			c.re = fractol->x_start + i * fractol->dx;
			c.im = fractol->y_start + j * fractol->dy;
			value = mandelbrot(c, 100);
			put_function(value, fractol, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void	render_julia(t_fractol *fractol)
{
	t_complex	z;
	int			i;
	int			j;
	int			value;

	fractol->dx = (fractol->x_fin - fractol->x_start) / (WIDTH);
	fractol->dy = (fractol->y_fin - fractol->y_start) / (HEIGHT);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			z.re = fractol->x_start + i * fractol->dx;
			z.im = fractol->y_start + j * fractol->dy;
			value = julia(z, fractol->arg, 100);
			put_function(value, fractol, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void	render_fractol(t_fractol *fractol)
{
	if (ft_strcmp(fractol->name, "m") == 0)
		render_mandelbrot(fractol);
	else if (ft_strcmp(fractol->name, "j") == 0)
		render_julia(fractol);
}
