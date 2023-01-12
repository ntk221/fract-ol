/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:22:14 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/12 22:07:55 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include "include/utils.h"
#include <X11/keysym.h>

// using namespace std;

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

void  my_mlx_pixel_put(t_mlx_system *system, int x, int y, int color)
{
  char  *dst;

  dst = system->addr + (y * system->line_length + x * (system->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

void  system_init(t_mlx_system *system)
{
    system->mlx = mlx_init();
    system->win = mlx_new_window(system->mlx, WIDTH, HEIGHT, "Hello, World");
    system->img = mlx_new_image(system->mlx, WIDTH, HEIGHT);
    system->addr = mlx_get_data_addr(system->img, &system->bits_per_pixel, &system->line_length, &system->endian);
}


void    fractol_init(t_fractol *fractol)
{
    fractol->x_start = -2.0;
    fractol->y_start = -2.0;
    fractol->x_fin = 2.0;
    fractol->y_fin = 2.0;
    double	dx = (fractol->x_fin - fractol->x_start)/(WIDTH);
	  double	dy = (fractol->y_fin - fractol->y_start)/(HEIGHT);
}

void    render_fractol(t_mlx_system *system, t_fractol * fractol)
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
                my_mlx_pixel_put(system, j, i, 0x00FF0000);
            }
        }
    }
    mlx_put_image_to_window(system->mlx, system->win, system->img, 0, 0); 
}

/*int  update(void *param)
{
  t_fractol *fractol = (t_fractol*)param;

  static int  frame;

  frame++;
  if (frame == 2)
  {
      fractol->x_start += 1;
      fractol->x_fin += 1;
  }
  else if (frame >= 4)
  {
      fractol->x_start +=1;
      fractol->x_fin += 1;
      frame = 0;
  }
  render_fractol(fractol);

  return (0);
}*/

int mouse_hook(int mousecode, t_mlx_system *system)
{
  if (mousecode == 4)
    zoom_in();
  else if(mousecode == 5)
    puts("scroll down!");

  // render(); ?

  return 0;
}

int main(int argc, char **argv)
{
    t_fractol     fractol;
    t_mlx_system  system;
    
    // フラクタル図形に関する初期化
    fractol_init(&fractol);

    // mlx系に関する初期化
    system_init(&system);

    //  関数に切る
        mlx_hook(system.win, 2, 1L<<0, close, &system);
        mlx_hook(system.win, 17, 1L<<2, close_2, &system);
    //

    //  mouse系のhooksの設定
        mlx_mouse_hook(system.win, mouse_hook, &system);
    //

    // 描画用の処理
    render_fractol(&system, &fractol);

    
    // mlx_loop_hook(fractol.mlx, *update, &fractol);
    

    mlx_loop(system.mlx);
}
