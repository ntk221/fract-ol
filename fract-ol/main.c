/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:22:14 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 03:29:40 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include "include/libft.h"

/*__attribute__((destructor))
static void destructor() {
	system("leaks -q fract-ol");
}*/

int		finish(t_fractol *fractol);
void	set_hooks(t_fractol *fractol);
void	handle_args(int argc, char **argv, t_fractol *fractol);

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

int	finish(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	die("Pressed cross button");
	return (0);
}
