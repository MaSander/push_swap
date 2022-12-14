/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time
*/

#include "operation.h"

t_stack *ft_rotate(t_stack *stack, char stack_name)
{
	t_stack *last;
	t_stack *new_first;

	new_first = stack->next;
	last = ft_lstlast(stack);
	new_first->last = 0;
	stack->next = 0;
	last->next = stack;
	ft_putstr_fd("r", 1);
	ft_putchar_fd(stack_name, 1);
	ft_putstr_fd("\n", 1);
	return (new_first);
}

t_stack *ft_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *last;
	t_stack *new_first;

	new_first = stack_a->next;
	last = ft_lstlast(stack_a);
	new_first->last = 0;
	stack_a->next = 0;
	last->next = stack_a;
	new_first = stack_b->next;
	last = ft_lstlast(stack_b);
	new_first->last = 0;
	stack_b->next = 0;
	last->next = stack_b;
	ft_putstr_fd("rr", 1);
	ft_putstr_fd("\n", 1);
	return (new_first);
}
