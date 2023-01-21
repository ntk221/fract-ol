/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:48:15 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/13 10:57:57 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include <X11/keysym.h>

void  system_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Hello, World");
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length, &fractol->endian);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->x_start = -2.0;
	fractol->y_start = 2.0;
	fractol->x_fin = 2.0;
	fractol->y_fin = -2.0;
}
