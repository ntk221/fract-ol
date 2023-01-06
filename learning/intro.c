#include <mlx.h>
#include <math.h>

typedef struct s_data
{
  void  *img;
  char  *addr;
  int    bits_per_pixel;
  int   line_length;
  int   endian;
} t_data;

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char  *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

void  call_pixel_put(t_data *data, int x1, int y1)
{
  int color   = 0x00FF0000;
  double  rad = (double)30 / 180 * M_PI;
  int length = 100;
  int x = 0;
  int y = 0;
  for(int l = 0; l < length; l++)
  {
    x = x1 + l * cos(rad);
    y = y1 + l * sin(rad);
    my_mlx_pixel_put(data, x, y, color);
  }
}

int	main(void)
{
	void	  *mlx;
  void    *mlx_win;
  t_data  img;

	mlx = mlx_init();
  mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello, World!");
  img.img = mlx_new_image(mlx, 1920, 1080);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
  //for(int i = 0; i < 1080; i++)
  //  my_mlx_pixel_put(&img, 5, i, 0x00FF0000);
  call_pixel_put(&img, 5, 5);
  mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  mlx_loop(mlx);
}

