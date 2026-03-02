#include "ft_printf.h"

int ft_print_nbr(int n)
{
    long nbr;
    int len;

    len = 0;
    nbr = (long)n;

    if(nbr < 0)
    {
        len += ft_print_char('-');
        nbr = -1 * nbr;
    }
    if(nbr >= 10)
    {
        len += ft_print_nbr(nbr / 10);
    }
    len += ft_print_char((nbr % 10) + '0');
    return (len);
}