/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:22:14 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/10 12:28:54 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include "include/utils.h"
#include <X11/keysym.h>

// using namespace std;

#include <stdio.h>
int close(int keycode, t_vars *vars)
{
  printf("%d\n", keycode); // esc -> 65307 ...????
  if(keycode == XK_Escape)
  {
    mlx_destroy_window(vars->mlx, vars->win);
    die("Pessed esc key");
  }
  return (0);
}

int close_2(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
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

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char  *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

void  init(t_vars *vars, t_data *img, int width, int height)
{
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, width, height, "Hello, World");
    mlx_hook(vars->win, 2, 1L<<0, close, &(*vars));
    mlx_hook(vars->win, 17, 1L<<2, close_2, &(*vars));
    img->img = mlx_new_image(vars->mlx, width, height);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

#define WIDTH  1920
#define HEIGHT 1080

int main(void)
{
    // 複素平面上の，ウィンドウにマッピングする部分?
    double x_start = -2.0;
	double x_fin = 2.0;
	double y_start = -2.0;
	double y_fin = 2.0;

    double dx = (x_fin - x_start)/(WIDTH);
    double dy = (y_fin - y_start)/(HEIGHT);
			
    t_vars    vars;
    t_data    img;
    t_fractol fractol;

    init(&vars, &img, WIDTH, HEIGHT);

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
                my_mlx_pixel_put(&img, j, i, 0x00FF0000);
                // mlx_pixel_put(mlx, mlx_win, j, i, 0x00FF0000);
            }
        }
    }
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_loop(vars.mlx);
}
