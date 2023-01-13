/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:22:14 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/13 10:51:25 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include <X11/keysym.h>

int key_hooks(int keycode, t_fractol *fractol)
{
	printf("%d\n", keycode);
	if(keycode == XK_Escape)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		die("Pressed esc key");
	}
	return (0);
}

int finish(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	die("Pressed cross button");
	return (0);
}

void  my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->line_length + x * (fractol->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    render_fractol(t_fractol * fractol)
{
  // if(fractol->img)
  //  fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->dx = (fractol->x_fin - fractol->x_start)/(WIDTH);
	fractol->dy = (fractol->y_fin - fractol->y_start)/(HEIGHT);
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			t_complex c;
			c.re = fractol->x_start + j * fractol->dx; // current real value
			c.im = fractol->y_start + i * fractol->dy;   // current imaginary value
			int value = mandelbrot(c, 100);
			if (value > 90)
				my_mlx_pixel_put(fractol, j, i, 0x00FF0000);
		}
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0); 
}

int main(int argc, char **argv)
{
	t_fractol	fractol;
	
	fractol_init(&fractol);
	printf("%lf\n", fractol.x_start);
	system_init(&fractol);
	render_fractol(&fractol);

	// 関数に切る
	mlx_hook(fractol.win, 2, 1L<<0, key_hooks, &fractol);
	mlx_mouse_hook(fractol.win, mouse_hooks, &fractol);
	mlx_hook(fractol.win, 17, 1L<<2, finish, &fractol);

	mlx_loop(fractol.mlx);
}
