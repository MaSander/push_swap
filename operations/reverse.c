// TODO: atualizar a HEAD de todos os NÓS, ou remover "HEAD" da struct
#include "operation.h"

t_stack *ft_reverse_rotate(t_stack *stack, char stack_name)
{
	t_stack *new_first;

	new_first = ft_lstlast(stack);
	new_first->last->next = 0;
	new_first->next = stack;
	new_first->last = 0;
	stack->last = new_first;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack_name, 1);
	ft_putstr_fd("\n", 1);
	return (new_first);
}

t_stack *ft_reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *new_first;

	new_first = ft_lstlast(stack_a);
	new_first->last->next = 0;
	new_first->next = stack_a;
	new_first->last = 0;
	stack_a->last = new_first;
	new_first = ft_lstlast(stack_b);
	new_first->last->next = 0;
	new_first->next = stack_b;
	new_first->last = 0;
	stack_b->last = new_first;
	ft_putstr_fd("rrr", 1);
	ft_putstr_fd("\n", 1);
	return (new_first);
}
