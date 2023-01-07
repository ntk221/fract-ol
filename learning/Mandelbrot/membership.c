#include <math.h>
#include <stdbool.h>
#include <assert.h>

typedef struct s_complex
{
    double re;
    double im;
} t_complex;

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

bool    mandelbrot(t_complex c, int maxiter)
{
    t_complex   z;

    z.re = 0.0;
    z.im = 0.0;
    for(int i = 0; i < maxiter; i++)
    {
        z = c_sum(c_mul(z, z), c);

        if (c_abs(z) > 4.0)
            return false;
    }
    return true;
}

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

void    test_mandelbrot(void)
{
    t_complex   c;
    c.re = 0.0;
    c.im = 0.0;
    bool res = mandelbrot(c, 40);
    assert(res == true);
}


int main(void)
{
    test_sum_complex();
    test_mul_complex();
    test_abs_complex();
    test_mandelbrot();
}