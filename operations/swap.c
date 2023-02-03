/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.
*/

#include "operation.h"

void	ft_swap(t_stack *stack, char stack_name)
{
	int	aux_number;
	int	aux_index;

	aux_number = stack->number;
	aux_index = stack->index;
	stack->number = stack->next->number;
	stack->index = stack->next->index;
	stack->next->number = aux_number;
	stack->next->index = aux_index;
	ft_putstr_fd("s", 1);
	ft_putchar_fd(stack_name, 1);
	ft_putstr_fd("\n", 1);
}

void	ft_swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	int	aux;

	aux = stack_a->number;
	stack_a->number = stack_a->next->number;
	stack_a->next->number = aux;
	aux = stack_b->number;
	stack_b->number = stack_b->next->number;
	stack_b->next->number = aux;
	ft_putstr_fd("ss", 1);
	ft_putstr_fd("\n", 1);
}
