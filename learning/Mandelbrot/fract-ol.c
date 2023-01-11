/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:22:14 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/11 10:23:22 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include "include/utils.h"
#include <X11/keysym.h>

#include <stdio.h>
int close(int keycode, t_mlx_system *system)
{
  printf("%d\n", keycode); // esc -> 65307 ...????
  if(keycode == XK_Escape)
  {
    mlx_destroy_window(system->mlx, system->win);
    die("Pressed esc key");
  }
  return (0);
}

int close_2(t_mlx_system *system)
{
    mlx_destroy_window(system->mlx, system->win);
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

void  my_mlx_pixel_put(t_mlx_system *system, int x, int y, int color)
{
  char  *dst;

  dst = system->addr + (y * system->line_length + x * (system->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

void  init_mlx_system(t_mlx_system *system)
{
    system->mlx = mlx_init();
    system->win = mlx_new_window(system->mlx, WIDTH, HEIGHT, "Hello, World");
    system->img = mlx_new_image(system->mlx, WIDTH, HEIGHT);
    system->addr = mlx_get_data_addr(system->img, &system->bits_per_pixel, &system->line_length, &system->endian);
}


void    init_fractol(t_fractol *fractol)
{
    fractol->x_start = -2.0;
    fractol->y_start = -2.0;
    fractol->x_fin = 2.0;
    fractol->y_fin = 2.0;
    double	dx = (fractol->x_fin - fractol->x_start)/(WIDTH);
	double	dy = (fractol->y_fin - fractol->y_start)/(HEIGHT);
}

void    render_fractol(t_fractol *fractol, t_mlx_system *system)
{
    fractol->dx = (fractol->x_fin - fractol->x_start)/(WIDTH);
    fractol->dy = (fractol->y_fin - fractol->y_start)/(HEIGHT);

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            t_complex c;
            c.re = fractol->x_start + j * fractol->dx;   // current real value
            c.im = fractol->y_start + i * fractol->dy;   // current imaginary value

            int value = mandelbrot(c, 100);
            if (value > 90)
                my_mlx_pixel_put(system, j, i, 0x00FF0000);
        }
    }
    mlx_put_image_to_window(system->mlx, system->win, system->img, 0, 0); 
}

int main(int argc, char **argv)
{
    t_fractol       fractol;
    t_mlx_system    system;
    
    // フラクタル図形 に関する情報を保存する構造体の初期化
    init_fractol(&fractol);

    // mlx系 に関する情報を保存する構造体の初期化
    init_mlx_system(&system);

    //  TODO: 関数に切る
        mlx_hook(system.win, 2, 1L<<0, close, &system);
        mlx_hook(system.win, 17, 1L<<2, close_2, &system);
    //

    //  TODO: mouse系のhooksの設定

    //

    // フラクタル図形の描画処理
    render_fractol(&fractol, &system);
    //
    mlx_loop(system.mlx);
}
