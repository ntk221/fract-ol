/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:22:14 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 02:53:52 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include "include/libft.h"
#include <X11/keysym.h>

int	key_hooks(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		die("Pressed esc key");
	}
	return (0);
}

int	finish(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	die("Pressed cross button");
	return (0);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->line_length + x * (fractol->bits / 8));
	*(unsigned int *)dst = color;
}

void	put_function(int value, t_fractol *fractol, int i, int j)
{
	if (value > 90)
		my_mlx_pixel_put(fractol, i, j, 0xE00000);
	else if (value > 70)
		my_mlx_pixel_put(fractol, i, j, 0x0E0000);
	else if (value > 50)
		my_mlx_pixel_put(fractol, i, j, 0xAA0000);
	else if (value > 30)
		my_mlx_pixel_put(fractol, i, j, 0x6E0000);
	else if (value > 10)
		my_mlx_pixel_put(fractol, i, j, 0x550000);
	else if (value > 5)
		my_mlx_pixel_put(fractol, i, j, 0x400000);
	else if (value > 4)
		my_mlx_pixel_put(fractol, i, j, 0x300000);
	else if (value > 3)
		my_mlx_pixel_put(fractol, i, j, 0x200000);
	else if (value > 2)
		my_mlx_pixel_put(fractol, i, j, 0x100000);
	else if (value > 1)
		my_mlx_pixel_put(fractol, i, j, 0x050000);
	else
		my_mlx_pixel_put(fractol, i, j, 0x000000);
}

void	render_mandelbrot(t_fractol *fractol)
{
	int			i;
	int			j;
	t_complex	c;
	int			value;

	fractol->dx = (fractol->x_fin - fractol->x_start) / (WIDTH);
	fractol->dy = (fractol->y_fin - fractol->y_start) / (HEIGHT);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			c.re = fractol->x_start + i * fractol->dx;
			c.im = fractol->y_start + j * fractol->dy;
			value = mandelbrot(c, 100);
			put_function(value, fractol, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void	render_julia(t_fractol *fractol)
{
	t_complex	z;
	int			i;
	int			j;
	int			value;

	fractol->dx = (fractol->x_fin - fractol->x_start) / (WIDTH);
	fractol->dy = (fractol->y_fin - fractol->y_start) / (HEIGHT);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			z.re = fractol->x_start + i * fractol->dx;
			z.im = fractol->y_start + j * fractol->dy;
			value = julia(z, fractol->arg, 100);
			put_function(value, fractol, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void	render_fractol(t_fractol *fractol);

int	expose_hooks(t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	return (0);
}

void	print_usage(void)
{
	ft_putendl_fd("Usage:", 2);
	ft_putendl_fd("\nYou can select two fractals", 2);
	ft_putendl_fd("\n\tm  Mandelbrot Set", 2);
	ft_putendl_fd("\tj  Julia Set", 2);
	ft_putendl_fd("\nIf, you select Julia, you can select number 0-2", 2);
	ft_putendl_fd("\nexample:\t", 2);
	ft_putendl_fd("\t./fractol J 0\n", 2);
}

void	handle_args(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 2)
	{
		print_usage();
		die("Error: not enough arguments");
	}
	else if (ft_strcmp(argv[1], "m") != 0 && ft_strcmp(argv[1], "j") != 0)
	{
		print_usage();
		die("Error: invalid fractol name");
	}
	if (ft_strcmp(argv[1], "j") == 0)
	{
		if (argc < 3)
		{
			print_usage();
			die("Error: invalid number of julia sets you can select");
		}
		fractol->arg = set_arg(ft_atoi(argv[2]));
	}
}

void	set_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win, 2, 1L << 0, key_hooks, fractol);
	mlx_mouse_hook(fractol->win, mouse_hooks, fractol);
	mlx_expose_hook(fractol->win, expose_hooks, fractol);
	mlx_hook(fractol->win, 17, 1L << 2, finish, fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	handle_args(argc, argv, &fractol);
	fractol.name = argv[1];
	fractol_init(&fractol);
	system_init(&fractol);
	set_hooks(&fractol);
	render_fractol(&fractol);
	mlx_loop(fractol.mlx);
}

void	render_fractol(t_fractol *fractol)
{
	if (ft_strcmp(fractol->name, "m") == 0)
		render_mandelbrot(fractol);
	else if (ft_strcmp(fractol->name, "j") == 0)
		render_julia(fractol);
}
