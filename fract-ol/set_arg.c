/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:26:21 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/22 03:28:25 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/complex.h"

t_complex	set_arg(int arg_num)
{
	t_complex	c;

	if (arg_num == 0)
	{
		c.re = -0.8;
		c.im = 0.15;
	}
	else if (arg_num == 1)
	{
		c.re = -0.7;
		c.im = 0.3;
	}
	else if (arg_num == 2)
	{
		c.re = -0.35;
		c.im = 0.65;
	}
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
