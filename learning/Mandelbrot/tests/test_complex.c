#include "../include/complex.h"
#include <math.h>
#include <assert.h>

void    test_sum_complex(void)
{
    t_complex   c1;
    c1.re = 1.0;
    c1.im = 1.0;

    t_complex   c2;
    c2.re = 1.0;
    c2.im = 1.0;

    t_complex res = c_sum(c1, c2);
    assert(res.re == 2.0 && res.im == 2.0);
}

/* test case is this -> https://www.mathsisfun.com/algebra/complex-number-multiply.html */
void    test_mul_complex(void)
{
    t_complex   c1;
    c1.re = 3.0;
    c1.im = 2.0;

    t_complex   c2;
    c2.re = 1.0;
    c2.im = 7.0;

    t_complex res = c_mul(c1, c2);
    assert(res.re == -11.0 && res.im == 23);
}

void    test_abs_complex(void)
{
    t_complex   c;

    c.re = -2.0;
    c.im = 3.0;

    double res = c_abs(c);
    assert(res == sqrt(13.0));
}

int main(void)
{
    test_sum_complex();
    test_mul_complex();
    test_abs_complex();
    return (0);
}
