/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:46:39 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 03:46:40 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include <X11/keysym.h>

int	expose_hooks(t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	return (0);
}

int	key_hooks(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		die("Pressed esc key");
	}
	return (0);
}
