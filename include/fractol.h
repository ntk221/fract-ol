/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:30:15 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 15:49:15 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <assert.h>
# include <stdio.h>
# include "complex.h"
# include <X11/keysym.h>
# include <stdlib.h>

# define WIDTH	640
# define HEIGHT	640

typedef struct s_fractol
{
	char		*name;
	t_complex	arg;
	double		x_start;
	double		x_fin;
	double		y_start;
	double		y_fin;
	double		dx;
	double		dy;

	void		*img;
	char		*addr;
	int			bits;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
}	t_fractol;

void		my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);

/* calculate fractol set */
int			mandelbrot(t_complex c, int maxiter);
int			julia(t_complex z, t_complex c, int maxiter);

/* initialize function */
void		system_init(t_fractol *fractol);
void		fractol_init(t_fractol *fractol);

/* mouse hooks */
int			mouse_hooks(int mousecode, int x, int y, t_fractol *fractol);
void		zoom_in(t_fractol *fractol);
void		zoom_out(t_fractol *fractol);

/* other hooks */
int			expose_hooks(t_fractol *fractol);
int			key_hooks(int keycode, t_fractol *fractol);

/* rendering function */
void		render_fractol(t_fractol *fractol);
void		render_mandelbrot(t_fractol *fractol);
void		render_julia(t_fractol *fractol);

/* util function */
t_complex	set_arg(double c_re, double c_im);
void		print_usage(void);
void		handle_args(int argc, char **argv, t_fractol *fractol);
void		die(char *s);
double  ft_atof(char *str);

#endif
