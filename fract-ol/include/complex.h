/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:43:18 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 03:43:15 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

t_complex	c_sum(t_complex c1, t_complex c2);

t_complex	c_mul(t_complex c1, t_complex c2);

double		c_abs(t_complex c);

#endif
