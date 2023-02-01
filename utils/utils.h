#ifndef UTILS_H
# define UTILS_H

# include "./../push_swap.h"

long int	ft_atoi(const char *str);
void		ft_free(void *ptr);
void		ft_free_array(char **ptr);

// Listas
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstclear(t_stack **lst);
void		ft_lstdelone(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(long int number);
int			ft_lstsize(t_stack *lst);
char		**ft_split(const char *s, char c);

/**
 * @file ft_pintables.c
 * @brief printa na tela uma string
 * @return quantidade de caracteres que printou
 */
size_t		ft_putstr_fd(char *s, int fd);

/**
 * @file ft_pintables.c
 * @brief printa na tela um char
 * @return quantidade de caracteres que printou
 */
size_t		ft_putchar_fd(char c, int fd);

int			is_sort(t_ps *ps);

/**
 * @file ft_findindex.c
 * @brief encontra um index menor que a referencia
 * @return menor index encontrado depois da referencia
 */
long long	find_smallest_than(t_stack *s, long long ref);
/**
 * @file ft_findindex.c
 * @brief encontra um index maior que a referencia
 * @return maior index encontrado depois da referencia
 */
long long	find_biggest_than(t_stack *s, long long ref);

#endif