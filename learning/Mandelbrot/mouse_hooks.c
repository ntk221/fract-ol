/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:41:10 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/20 22:25:56 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fract-ol.h"
#include <X11/keysym.h>

void	zoom_in(t_fractol *fractol)
{
	fractol->x_start += 0.05;
	fractol->x_fin -= 0.05;
	fractol->y_start -= 0.05;
	fractol->y_fin += 0.05;
	mlx_destroy_image(fractol->mlx, fractol->img);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length, &fractol->endian);
	render_fractol(fractol);
}

void	zoom_out(t_fractol *fractol)
{
	fractol->x_start -= 0.05;
	fractol->x_fin += 0.05;
	fractol->y_start += 0.05;
	fractol->y_fin -= 0.05;
	mlx_destroy_image(fractol->mlx, fractol->img);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length, &fractol->endian);
	render_fractol(fractol);
}

int mouse_hooks(int mousecode, int x, int y, t_fractol *fractol)
{
  x = x;
  y = y;
	if (mousecode == 4)
	  zoom_in(fractol);
	else if(mousecode == 5)
	  zoom_out(fractol);
	return 0;
}
