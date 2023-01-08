#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

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

int    mandelbrot(t_complex c, int maxiter)
{
    t_complex   z;

    z.re = 0.0;
    z.im = 0.0;
    for(int i = 0; i < maxiter; i++)
    {
        z = c_sum(c_mul(z, z), c);

        if (c_abs(z) > 4.0)
            return i;
    }
    return maxiter;
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
    int res = mandelbrot(c, 40);
    printf("%d\n", res);
}


/*int main(void)
{
    test_sum_complex();
    test_mul_complex();
    test_abs_complex();
    test_mandelbrot();
}*/

int main(void)
{
    int width = 140;
    int height = 33;

    double x_start = -2.0;
	double x_fin = 1.0;
	double y_start = -1.0;
	double y_fin = 1.0;

    double dx = (x_fin - x_start)/(width - 1); // 変化率？
    double dy = (y_fin - y_start)/(height - 1);

    string char_ = "\u2588";

	string black = "\033[22;30m";
	string red = "\033[22;31m";
	string l_red = "\033[01;31m";
	string green = "\033[22;32m";
	string l_green = "\033[01;32m";
	string orange = "\033[22;33m";
	string yellow = "\033[01;33m";
	string blue = "\033[22;34m";
	string l_blue = "\033[01;34m";
	string magenta = "\033[22;35m";
	string l_magenta = "\033[01;35m";
	string cyan = "\033[22;36m";
	string l_cyan = "\033[01;36m";
	string gray = "\033[22;37m";
	string white = "\033[01;37m";

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            t_complex c;
            c.re = x_start + j * dx; // current real value
            c.im = y_fin - i * dy; // current imaginary value

            int value = mandelbrot(c, 100);

           if (value == 100) {cout << " ";}
			else if (value > 90) {cout << red << char_;}
			else if (value > 70) {cout << l_red << char_;}
			else if (value > 50) {cout << orange << char_;}
			else if (value > 30) {cout << yellow << char_;}
			else if (value > 20) {cout << l_green << char_;}
			else if (value > 10) {cout << green << char_;}
			else if (value > 5) {cout << l_cyan << char_;}
			else if (value > 4) {cout << cyan << char_;}
			else if (value > 3) {cout << l_blue << char_;}
			else if (value > 2) {cout << blue << char_;}
			else if (value > 1) {cout << magenta << char_;}
			else {cout << l_magenta << char_;} 

            cout << "\033[0m";
        }
        cout << endl;
    }
}