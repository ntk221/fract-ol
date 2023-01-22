/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:26:21 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 15:46:44 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/complex.h"

t_complex	set_arg(double c_re, double c_im)
{
	t_complex	c;

	c.re = c_re;
	c.im = c_im;
	return (c);
}

/*#include <assert.h>
int main(void)
{
  t_complex c = set_arg(0);
  assert(c.re == -0.8);
  c = set_arg(1);
  assert(c.im == 0.3);
}*/
