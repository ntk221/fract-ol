#include <math.h>
#include <stdbool.h>

typedef struct s_complex
{
    double re;
    double im;
} t_complex;

bool    mandelbrot(t_complex c)
{
    return true;
}

void    test_mandelbrot(void)
{
    t_complex   c;
    c.re = 1.0;
    c.im = 1.0;
    bool res = mandelbrot(c);
}

int main(void)
{
    test_mandelbrot();
}