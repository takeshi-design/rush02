NAME = libftprint.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:.c=.o)

INCDIR = 

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $@ $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re