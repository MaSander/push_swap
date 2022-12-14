#ifndef OPERATION_H
# define OPERATION_H

# include "./../push_swap.h"

void	ft_swap(t_stack *stack, char stack_name);
void	ft_swap_ab(t_stack *stack_a, t_stack *stack_b);
t_stack	*ft_rotate(t_stack *stack, char stack_name);
t_stack	*ft_rotate_ab(t_stack *stack_a, t_stack *stack_b);
t_stack	*ft_reverse_rotate(t_stack *stack, char stack_name);
t_stack	*ft_reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	ft_push(t_stack **stack_sub, t_stack **stack_add, char stack_name);

#endif