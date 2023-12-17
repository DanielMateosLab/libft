CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = $(wildcard ft_*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

deb:
	$(CC) $(CFLAGS) -g3 -fsanitize=address main.c $(SRCS) -o test