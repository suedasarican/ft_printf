NAME    = libftprintf.a
SRCS    = ft_printf.c ft_print_char.c ft_print_str.c ft_print_nbr.c \
          ft_print_unbr.c ft_print_ptr.c ft_print_hex.c
OBJS    = $(SRCS:.c=.o)
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re