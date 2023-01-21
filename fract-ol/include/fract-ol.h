#include <math.h>
#include <mlx.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "complex.h"
#include "utils.h"
#include <Xlib.h>
#include <stdlib.h>

#define WIDTH	640
#define HEIGHT	640

typedef struct s_fractol
{
	char		      *name;
  t_complex     arg;
	double		    x_start;
	double		    x_fin;
	double		    y_start;
	double		    y_fin;
	double		    dx; 
	double		    dy; 

	void		*img;
	char		*addr;
	int			bits;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
} t_fractol;

/* calculate fractol set */
int	mandelbrot(t_complex c, int maxiter);
int	julia(t_complex z, t_complex c, int maxiter);

/* initialize function */
void	system_init(t_fractol *fractol);
void	fractol_init(t_fractol *fractol);

/* mouse hooks */
int		mouse_hooks(int mousecode, int x, int y, t_fractol *fractol);
void	zoom_in(t_fractol *fractol);
void	zoom_out(t_fractol *fractol);

/* rendering function */
void	render_fractol(t_fractol *fractol);
void	render_mandelbrot(t_fractol * fractol);
void	render_julia(t_fractol * fractol);

/* util function */
t_complex set_arg(int arg_num);
void      print_usage(void);
void      handle_args(int argc, char **argv, t_fractol *fractol);


