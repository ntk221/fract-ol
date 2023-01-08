#include "include/complex.h"
#include <math.h>


t_complex   c_sum(t_complex c1, t_complex c2)
{
    t_complex  sum;

    sum.re = c1.re + c2.re;
    sum.im = c1.im + c2.im;
    return (sum);
}

t_complex   c_mul(t_complex c1, t_complex c2)
{
    t_complex  mul;

    mul.re = (c1.re * c2.re) - (c1.im * c2.im);
    mul.im = (c1.re * c2.im) + (c2.re * c1.im);
    return (mul);
}

double      c_abs(t_complex c)
{
    return (sqrt((c.re * c.re) + (c.im * c.im)));
}