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

/**
 * @file ft_strlen.c
 * @brief conta o comprimento de uma sting ou vetor
 * @return quantidade de bytes de uma string
 */
size_t	ft_strlen(const char *s);

/**
 * @file ft_pintables.c
 * @brief printa na tela uma string
 * @return quantidade de caracteres que printou
 */
size_t	ft_putstr_fd(char *s, int fd);

/**
 * @file ft_pintables.c
 * @brief printa na tela um char
 * @return quantidade de caracteres que printou
 */
size_t	ft_putchar_fd(char c, int fd);

int		is_sort(t_ps *ps);


void ft_update_head_stack(t_stack *stack); //Validar utilização

#endif