NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c put_str_print.c put_at_the_specifier.c  put_at_the_specifier2.c \
	utility_f.c utility_f2.c check_error_and_put.c

OBJS = $(SRCS:.c=.o)

INCDIR = -I.

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $@ $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
		make fclean
		make all

.PHONY: all clean fclean re
