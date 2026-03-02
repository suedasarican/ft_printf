# ft_printf

*This project has been created as part of the 42 curriculum by [Adın Soyadın].*

## Description
This project is a custom implementation of the standard C library function `printf`. The goal is to understand **variadic functions** in C (functions that take a variable number of arguments) and to manage formatted output.

The resulting library, `libftprintf.a`, mimics the behavior of the original printf for specific conversions. It is designed to be included in future 42 projects where the use of the standard printf is forbidden.

## Instructions

### Compilation
The project includes a Makefile that compiles the source files and creates the static library.

* `make`: Compiles the source files and generates `libftprintf.a`.
* `make clean`: Removes the object files (`.o`).
* `make fclean`: Removes the object files and the library file.
* `make re`: Performs a full clean and recompiles the project.

### Usage
To use this function in your code, include the header file and link the library during compilation.

**1. Include the header:**
```c
#include "ft_printf.h"
```
**2. Example Main:**
```c
int main(void)
{
    ft_printf("Hello, %s! The answer is %d.\n", "User", 42);
    ft_printf("Hexadecimal: %x, Pointer: %p\n", 255, &var);
    return (0);
}
```
**3. Compile with your main:**
```
cc main.c libftprintf.a -o my_program
```

Implementation Details
The Algorithm
The logic is straightforward and avoids complex buffer management. The core function ft_printf iterates through the format string character by character.

Iteration: The main loop checks every character in the string.

Dispatching: If a % sign is found, the index is incremented, and the ft_formats function is called.

Handling Types: ft_formats acts as a router. It takes the va_list and the format character (e.g., 's', 'd', 'x') and calls the corresponding helper function (like ft_print_str or ft_print_hex).

Counting: Every helper function returns the number of characters printed. This total count is accumulated and returned at the end, exactly mimicking the return value of the real printf.

Supported Conversions
My implementation handles the following format specifiers:

Specifier,Description,Handled By
%c,Prints a single character.,ft_print_char
%s,Prints a string.,ft_print_str
%p,Prints a void * pointer in hexadecimal.,ft_print_ptr
%d,Prints a decimal (base 10) number.,ft_print_nbr
%i,Prints an integer in base 10.,ft_print_nbr
%u,Prints an unsigned decimal (base 10) number.,ft_print_unbr
%x,Prints a number in hexadecimal (lowercase).,ft_print_hex
%X,Prints a number in hexadecimal (uppercase).,ft_print_hex
%%,Prints a percent sign.,ft_print_char

Resources & AI Usage
Resources
The C Programming Language: For understanding standard library behaviors.

Linux Man Pages: man printf and man stdarg to understand va_start, va_arg, and va_copy.
## AI Usage
AI tools were consulted for conceptual clarity regarding variadic functions and documentation structure. The actual code implementation and logic were developed manually to ensure a solid grasp of the core mechanics.