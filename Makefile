NAME=push_swap
SRCS=push_swap.c \
	./utils/ft_atoi.c \
	./utils/ft_lstadd_back.c \
	./utils/ft_lstadd_front.c \
	./utils/ft_lstclear.c \
	./utils/ft_lstdelone.c \
	./utils/ft_lstlast.c \
	./utils/ft_lstnew.c \
	./utils/ft_lstsize.c

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
