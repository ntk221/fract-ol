#include <math.h>
#include <mlx.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "complex.h"
#include "utils.h"
#include <Xlib.h>
#include <stdlib.h>

#define WIDTH 	640
#define HEIGHT 	640

/*typedef struct s_data
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
*/

typedef struct s_fractol
{
	double	x_start;
	double	x_fin;
	double	y_start;
	double	y_fin;
	double	dx; // x_fin - x_start)/(WIDTH);
	double	dy; // (y_fin - y_start)/(HEIGHT);

	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
} t_fractol;

/*typedef struct s_mlx_system
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
} t_mlx_system;*/

int	mandelbrot(t_complex c, int maxiter);

/* initialize function */
void	system_init(t_fractol *fractol);
void	fractol_init(t_fractol *fractol);

/* mouse hooks */
int		mouse_hooks(int mousecode, int x, int y, t_fractol *fractol);
void	zoom_in(t_fractol *fractol);
void	zoom_out(t_fractol *fractol);

/* rendering function */
void	render_fractol(t_fractol * fractol);