CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = $(filter-out %_bonus.c, $(wildcard ft_*.c))
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(wildcard ft_*_bonus.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

deb:
	$(CC) $(CFLAGS) -g3 -fsanitize=address main.c $(SRCS) $(BONUS_OBJS) -o test
