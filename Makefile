NAME=push_swap
SRCS=push_swap.c \
	./verify.c \
	./operation.c \
	./sort_algorithm.c \
	./sort_five.c \
	./ft_atoi.c \
	./ft_lstutils.c \
	./ft_free.c \
	./ft_pintables.c \

OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS=-Werror -Wall -Wextra -g3
HEADER=push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
