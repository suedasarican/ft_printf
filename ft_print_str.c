#include "ft_printf.h"

int ft_print_str(char *str)
{
    int i;

    i = 0;
    if(str == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }
    else
    {
        while(str[i] != '\0')
        {
            ft_print_char(str[i]);
            i++;
        }
    }
    return (i);
}