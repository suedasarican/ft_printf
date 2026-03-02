#include "ft_printf.h"

int ft_print_hex(unsigned int n, const char format)
{
    unsigned int len;
    char *base;

    len = 0;
    if(format == 'x')
        base =  "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    if(n >= 16)
    {
        len += ft_print_hex(n / 16, format);
    }
    len += ft_print_char(base[(n % 16)]);
    return (len);

}