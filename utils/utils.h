#ifndef UTILS_H
# define UTILS_H

# include "./../push_swap.h"

int	ft_atoi(const char *str);
void	ft_free(void *ptr);

// Listas
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);
void	ft_lstdelone(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int number);
int		ft_lstsize(t_stack *lst);

#endif