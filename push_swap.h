/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:18:23 by oburato           #+#    #+#             */
/*   Updated: 2023/02/07 23:20:57 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define MAXINT 2147483648L
# define MININT -2147483649L

typedef struct s_stack
{
	long long int		number;
	long long int		index;
	struct s_stack		*head;
	struct s_stack		*last;
	struct s_stack		*next;
}	t_stack;

typedef struct s_ps
{
	int				lst_len;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_ps;

int			is_sort(t_ps *ps);
t_stack		*sort_three(t_stack *s);
t_stack		*sort_two(t_stack *s);
void		sort_five(t_ps *ps);
int			ft_radix(t_ps *ps);
t_stack		*order_three(t_stack *s);

int			verify_argv(char **argv);
int			verify_lst_is_sorted(t_stack *s);

void		ft_swap(t_stack *stack, char stack_name);
t_stack		*ft_rotate(t_stack *stack, char stack_name);
t_stack		*ft_reverse_rotate(t_stack *stack, char stack_name);
void		ft_push(t_stack **stack_sub, t_stack **stack_add, char stack_name);

void		ft_free(void *ptr);
void		ft_free_array(char **ptr);

void		ft_lstclear(t_stack **lst);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(long int number);

long int	ft_atoi(const char *str);
size_t		ft_putstr_fd(char *s, int fd);
size_t		ft_putchar_fd(char c, int fd);

#endif