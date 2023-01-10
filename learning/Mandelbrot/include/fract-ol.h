#include <math.h>
#include <mlx.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "complex.h"
#include <Xlib.h>
#include <stdlib.h>

typedef struct s_data
{
  void  *img;
  char  *addr;
  int    bits_per_pixel;
  int   line_length;
  int   endian;
} t_data;

typedef struct s_vars
{
  void  *mlx;
  void  *win;
} t_vars;

typedef struct s_fractol
{
  void  *img;
  char  *addr;
  int    bits_per_pixel;
  int   line_length;
  int   endian;
  void  *mlx;
  void  *win;
} t_fractol;
