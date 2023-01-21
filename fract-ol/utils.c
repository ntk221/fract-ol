/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:03:32 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/21 23:06:49 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fract-ol.h"
#include <unistd.h>
#include <string.h>
#include "include/libft.h"

void	die(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}
