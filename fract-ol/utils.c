/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:03:32 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 16:40:32 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"
#include "include/libft.h"

void	die(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

void	print_usage(void)
{
	ft_putendl_fd("Usage:", 2);
	ft_putendl_fd("\nYou can select two fractals", 2);
	ft_putendl_fd("\n\tm  Mandelbrot Set", 2);
	ft_putendl_fd("\tj  Julia Set", 2);
	ft_putstr_fd("\nIf you select Julia, you can select two parameters.", 2);
	ft_putendl_fd("Each parameters must satisfy following condition", 2);
	ft_putendl_fd("\n\t-2.0 <= c_re, c_im <= 2.0", 2);
	ft_putendl_fd("\nexample:\t", 2);
	ft_putendl_fd("\t./fractol j -0.8 0.15\n", 2);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->line_length + x * (fractol->bits / 8));
	*(unsigned int *)dst = color;
}

static double	atof_loop(char *str, double d, double e)
{
	while (*str != '\0' && ft_isdigit(*str))
	{
		d += e * (*str++ - '0');
		if (d > 2.0)
		{
			print_usage();
			die("Error: invalid parameters");
		}
		e *= 0.1;
	}
	return (d);
}

double	ft_atof(char *str)
{
	double	d;
	double	e;
	int		sign;

	d = 0.0;
	e = 0.1;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
		d = d * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		d = atof_loop(str, d, e);
	}
	return (d * sign);
}
