/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:41:10 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/21 23:03:00 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fract-ol.h"
#include <X11/keysym.h>

void	zoom_in(t_fractol *f)
{
	f->x_start += 0.05;
	f->x_fin -= 0.05;
	f->y_start -= 0.05;
	f->y_fin += 0.05;
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits, &f->line_length, &f->endian);
	render_fractol(f);
}

void	zoom_out(t_fractol *f)
{
	f->x_start -= 0.05;
	f->x_fin += 0.05;
	f->y_start += 0.05;
	f->y_fin -= 0.05;
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits, &f->line_length, &f->endian);
	render_fractol(f);
}

int	mouse_hooks(int mousecode, int x, int y, t_fractol *fractol)
{
	x = x;
	y = y;
	if (mousecode == 4)
		zoom_in(fractol);
	else if (mousecode == 5)
		zoom_out(fractol);
	return (0);
}
