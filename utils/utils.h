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
 * @file ft_clonelst.c
 * @brief clona a stack
 * @return ponteiro para uma nova struct
 * @warning tem que da free
 */
t_stack	*ft_clonelst(t_stack *lst);

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

/**
 * @file ft_findindex.c
 * @brief encontra menor index de uma lista
 * @return menor index encontrado
 */
int	find_smallest_index(t_stack *s);
/**
 * @file ft_findindex.c
 * @brief encontra maior index de uma lista
 * @return maior index encontrado
 */
int	find_biggest_index(t_stack *s);


void ft_update_head_stack(t_stack *stack); //Validar utilização

#endif