/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:22:14 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/13 00:13:08 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include "include/utils.h"
#include <X11/keysym.h>

#include <stdio.h>
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

int close_2(t_fractol *fractol)
{
    mlx_destroy_window(fractol->mlx, fractol->win);
    die("Pressed cross button");
    return (0);
}

int    mandelbrot(t_complex c, int maxiter)
{
    t_complex   z;

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

void  my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
  char  *dst;

  dst = fractol->addr + (y * fractol->line_length + x * (fractol->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

void  system_init(t_fractol *fractol)
{
    fractol->mlx = mlx_init();
    fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Hello, World");
    fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length, &fractol->endian);
}


void    fractol_init(t_fractol *fractol)
{
    fractol->x_start = -2.0;
    fractol->y_start = 2.0;
    fractol->x_fin = 2.0;
    fractol->y_fin = -2.0;
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

void	zoom_in(t_fractol *fractol)
{
	fractol->x_start += 0.05;
	fractol->x_fin -= 0.05;
	fractol->y_start -= 0.05;
	fractol->y_fin += 0.05;
  // mlx_clear_window(fractol->mlx, fractol->win);
  mlx_destroy_image(fractol->mlx, fractol->img);
  fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
  fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length, &fractol->endian);
	render_fractol(fractol);
}

#include <stdio.h>
int mouse_hooks(int mousecode, int x, int y, t_fractol *fractol)
{
  if (mousecode == 4)
    zoom_in(fractol);
  else if(mousecode == 5)
    1;// zoom_out(fractol);*/
  // printf("%lf", fractol->hoge);

  // render(); ?

  return 0;
}

int main(int argc, char **argv)
{
    t_fractol	fractol;
    
    fractol_init(&fractol);
    printf("%lf\n", fractol.x_start);
    system_init(&fractol);

    render_fractol(&fractol);

    //  TODO: 関数に切る
    mlx_hook(fractol.win, 2, 1L<<0, key_hooks, &fractol);
    mlx_hook(fractol.win, 17, 1L<<2, close_2, &fractol);

    mlx_mouse_hook(fractol.win, mouse_hooks, &fractol);

    // 描画用の処理
    // render_fractol(&fractol);

    mlx_loop(fractol.mlx);
}
