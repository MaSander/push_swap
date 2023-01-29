NAME=push_swap
SRCS=push_swap.c \
	./verify.c \
	./insert_sort.c \
	./init_stack.c \
	./index_queue.c \
	./sort_algorithm.c \
	./utils/ft_atoi.c \
	./utils/ft_lstadd_back.c \
	./utils/ft_lstadd_front.c \
	./utils/ft_lstclear.c \
	./utils/ft_lstdelone.c \
	./utils/ft_lstlast.c \
	./utils/ft_lstnew.c \
	./utils/ft_lstsize.c \
	./utils/ft_update_head_stack.c \
	./utils/ft_free.c \
	./utils/ft_strlen.c \
	./utils/ft_pintables.c \
	./utils/is_sort.c \
	./utils/ft_clonelst.c \
	./utils/ft_find_index.c \
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

check:
	make re && ARG=`ruby -e "puts (-1000..1000).to_a.shuffle.join(' ')"`; echo $ARG; ./push_swap $ARG | ./test/checker_linux $ARG

view:
	./venv/bin/python3 ./pyviz.py `ruby -e "puts (1..70).to_a.shuffle.join(' ')"`

valgrind: re
	rm -rf valgrind.log
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes --log-file=valgrind.log ./$(NAME) 1 2 3 4 5 6 7 8