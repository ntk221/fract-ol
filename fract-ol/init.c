/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:48:15 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/21 22:53: by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"
#include <X11/keysym.h>

void	system_init(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Hello, World");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits, &f->line_length, &f->endian);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->x_start = -2.0;
	fractol->y_start = 2.0;
	fractol->x_fin = 2.0;
	fractol->y_fin = -2.0;
}
