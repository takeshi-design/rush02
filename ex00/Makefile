NAME = rush-02

SRCS = main.c put_num_digits.c put_num_ex.c put_num.c read_dict.c put_error.c utilities.c utilities_ex.c \
	ignore_char.c have_required_num.c malloc_dict.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCDIR = -I.


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re