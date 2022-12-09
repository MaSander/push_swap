#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include "./../push_swap.h"

typedef struct s_stack
{
	int		number;
	struct s_stack	*head;
	struct s_stack	*tail;
	struct s_stack	*last;
	struct s_stack *next;
} t_stack;

int	ft_atoi(const char *str);

// Listas
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);
void	ft_lstdelone(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int number);
int		ft_lstsize(t_stack *lst);

#endif