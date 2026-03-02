#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *format, ...);
int ft_print_char(int c);
int ft_print_str(char *str);
int ft_print_nbr(int n);
int ft_print_ptr(void *ptr);
int ft_print_hex(unsigned int n, const char format);
int ft_print_unbr(unsigned int n);
#endif