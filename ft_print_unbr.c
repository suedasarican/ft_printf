#include "ft_printf.h"

int ft_print_unbr(unsigned int n)
{
    int len;

    len = 0;
    if(n >= 10)
    {
        len += ft_print_unbr(n / 10);
    }
    len += ft_print_char((n % 10) + '0');
    return (len);
}