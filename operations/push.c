/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/

#include "./operation.h"

void	ft_push(t_stack **stack_sub, t_stack **stack_add, char stack_name)
{
	t_stack *Added;
	t_stack *subtracted;

	if(!*stack_sub)
		return ;
	Added = *stack_add;
	subtracted = *stack_sub;
	*stack_sub = subtracted->next;
	subtracted->last = 0;
	*stack_add = subtracted;
	if (Added)
	{
		subtracted->next = Added;
		Added->last = subtracted;
	}
	else
	{
		subtracted->next = NULL;
		subtracted->last = NULL;
	}
	ft_putstr_fd("p", 1);
	ft_putchar_fd(stack_name, 1);
	ft_putstr_fd("\n", 1);
}
