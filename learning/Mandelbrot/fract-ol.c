/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:22:14 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/10 22:51:05 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include "include/utils.h"
#include <X11/keysym.h>

// using namespace std;

#include <stdio.h>
int close(int keycode, t_fractol *fractol)
{
  printf("%d\n", keycode); // esc -> 65307 ...????
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
    die("Pessed cross button");
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
    fractol->y_start = -2.0;
    fractol->x_fin = 2.0;
    fractol->y_fin = 2.0;
    double	dx =(fractol->x_fin - fractol->x_start)/(WIDTH);
	double	dy= (fractol->y_fin - fractol->y_start)/(HEIGHT);
}

void    render_fractol(t_fractol *fractol)
{
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
            {
                my_mlx_pixel_put(fractol, j, i, 0x00FF0000);
            }
        }
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0); 
}

int main(int argc, char **argv)
{
    t_fractol fractol;
    
    // TODO: fractol に関する init
    fractol_init(&fractol);

    // mlx系に関する init
    system_init(&fractol);

    //  TODO: 関数に切る
        mlx_hook(fractol.win, 2, 1L<<0, close, &fractol);
        mlx_hook(fractol.win, 17, 1L<<2, close_2, &fractol);
    //

    //  TODO: mouse系のhooksの設定

    //

    // TODO: 描画用の関数として切り出す
    render_fractol(&fractol);
    //
    mlx_loop(fractol.mlx);
}
