NAME=push_swap
SRCS=push_swap.c \
	./verify.c \
	./init_stack.c \
	./sort_algorithm.c \
	./utils/ft_atoi.c \
	./utils/ft_lstlast.c \
	./utils/ft_lstnew.c \
	./utils/ft_lstsize.c \
	./utils/ft_free.c \
	./utils/ft_pintables.c \
	./utils/is_sort.c \
	./utils/ft_split.c \
	./radix/ft_radix.c \
	./operations/swap.c \
	./operations/rotate.c \
	./operations/reverse.c \
	./operations/push.c

OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS= -O3 -Werror -Wall -Wextra -g3
HEADER=push_swap.h ./utils/utils.h

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

test: re
	cp ./push_swap ./test/push_swap
	bash ./test/tester.sh
