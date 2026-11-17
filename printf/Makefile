SRCS	= ft_printf.c srcs/ft_printf_main.c
OBJS	= $(SRCS:.c=.o)
HEADER	= ft_printf.h
NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS) clean
	ar rcs $(NAME) $(OBJS) libft/libft.a

libft: 
	cd $(PWD)/libft && make all clean

.PHONY: all, clean, fclean, re

%.o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@
