

typedef struct s_complex
{
    double re;
    double im;
} t_complex;

t_complex   c_sum(t_complex c1, t_complex c2);

t_complex   c_mul(t_complex c1, t_complex c2);

double      c_abs(t_complex c);
