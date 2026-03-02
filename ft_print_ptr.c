#include "ft_printf.h"

int ft_hex(unsigned long n)
{
    int len;
    char *base;

    len = 0;
    base = "0123456789abcdef";

    if(n >= 16)
    {
        len += ft_hex(n / 16);
    }
    len += ft_print_char(base[(n % 16)]);
    return (len);
}
int ft_print_ptr(void *ptr)
{
    unsigned long pt;
    int len;

    len = 0;
    pt =(unsigned long)ptr;

    if(ptr == NULL)
    {
        write(1, "(nil)", 5);
        return (5);
    }
    len += write(1, "0x", 2);
    len += ft_hex(pt);
    return (len);
}