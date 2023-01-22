#include <stdio.h>

char    *uitoa(unsigned int num, int base)
{
    int     i;
    int     len;
    char    *str;
    int     n;
    int     rem;

    i = 0;
    len = 0;
    n = num;
    while(n > 0)
    {
        n = n / base;
        len++;
    }
    str = (char *)malloc(sizeof(char) * len + 1);
    str[len + 1] = '\0';
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
}

int main(void)
{
    int hex = 0xA;
    //printf("%d\n", hex);
    char *res = ft_itoa(hex, 16);
}