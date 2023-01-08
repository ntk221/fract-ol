#include <math.h>
#include <mlx.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
// #include <string>
// #include <iostream>
#include "include/complex.h"

// using namespace std;

typedef struct s_data
{
  void  *img;
  char  *addr;
  int    bits_per_pixel;
  int   line_length;
  int   endian;
} t_data;

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

void    test_mandelbrot(void)
{
    t_complex   c;
    c.re = 0.0;
    c.im = 0.0;
    int res = mandelbrot(c, 40);
    // printf("%d\n", res);
}

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char  *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

int main(void)
{
    int width = 1080;
    int height = 1920;

    // 複素平面上の，ウィンドウにマッピングする部分?
    double x_start = -2.0;
	double x_fin = 2.0;
	double y_start = -2.0;
	double y_fin = 2.0;

    double dx = (x_fin - x_start)/(width);
    double dy = (y_fin - y_start)/(height);

    /*string char_ = "\u2588";

	string black = "\033[22;30m";
	string red = "\033[22;31m";
	string l_red = "\033[01;31m";
	string green = "\033[22;32m";
	string l_green = "\033[01;32m";
	string orange = "\033[22;33m";
	string yellow = "\033[01;33m";
	string blue = "\033[22;34m";
	string l_blue = "\033[01;34m";
	string magenta = "\033[22;35m";
	string l_magenta = "\033[01;35m";
	string cyan = "\033[22;36m";
	string l_cyan = "\033[01;36m";
	string gray = "\033[22;37m";
	string white = "\033[01;37m";

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            t_complex c;
            c.re = x_start + j * dx; // current real value
            c.im = y_fin - i * dy; // current imaginary value

            int value = mandelbrot(c, 100);

           if (value == 100) {cout << " ";}
			else if (value > 90) {cout << red << char_;}
			else if (value > 70) {cout << l_red << char_;}
			else if (value > 50) {cout << orange << char_;}
			else if (value > 30) {cout << yellow << char_;}
			else if (value > 20) {cout << l_green << char_;}
			else if (value > 10) {cout << green << char_;}
			else if (value > 5) {cout << l_cyan << char_;}
			else if (value > 4) {cout << cyan << char_;}
			else if (value > 3) {cout << l_blue << char_;}
			else if (value > 2) {cout << blue << char_;}
			else if (value > 1) {cout << magenta << char_;}
			else {cout << l_magenta << char_;} 

            cout << "\033[0m";
        }
        cout << endl;
    }*/

    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, width, height, "Hello, Woeld");
    img.img = mlx_new_image(mlx, width, height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            t_complex c;
            c.re = x_start + j * dx; // current real value
            c.im = y_fin - i * dy; // current imaginary value

            int value = mandelbrot(c, 100);
            if (value > 90)
            {
                my_mlx_pixel_put(&img, j, i, 0x00FF0000);
                // mlx_pixel_put(mlx, mlx_win, j, i, 0x00FF0000);
            }
        }
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
