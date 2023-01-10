/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:22:14 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/10 14:03:35 by kazuki           ###   ########.fr       */
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

void  init(t_fractol *fractol, int width, int height)
{
    fractol->mlx = mlx_init();
    fractol->win = mlx_new_window(fractol->mlx, width, height, "Hello, World");
    fractol->img = mlx_new_image(fractol->mlx, width, height);
    fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length, &fractol->endian);
}

#define WIDTH  1920
#define HEIGHT 1080

int main(void)
{
    // 複素平面上の，ウィンドウにマッピングする部分?
    double x_start = -1.0;
	double x_fin = 1.0;
	double y_start = -1.0;
	double y_fin = 1.0;

    double dx = (x_fin - x_start)/(WIDTH);
    double dy = (y_fin - y_start)/(HEIGHT);
			
    t_fractol fractol;

    init(&fractol, WIDTH, HEIGHT);

    //  TODO: 関数に切る
        mlx_hook(fractol.win, 2, 1L<<0, close, &fractol);
        mlx_hook(fractol.win, 17, 1L<<2, close_2, &fractol);
    //

    //  TODO: mouse系のhooksの設定

    //

    // TODO: 描画用の関数として切り出す
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            t_complex c;
            c.re = x_start + j * dx; // current real value
            c.im = y_start + i * dy;   // current imaginary value

            int value = mandelbrot(c, 100);
            if (value > 90)
            {
                my_mlx_pixel_put(&fractol, j, i, 0x00FF0000);
                // mlx_pixel_put(mlx, mlx_win, j, i, 0x00FF0000);
            }
        }
    }
    mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
    //
    mlx_loop(fractol.mlx);
}
