#include "utils.h"

void	ft_update_head_stack(t_stack *stack)
{
	t_stack *head;

	head = stack;
	while (stack)
	{
		stack->head = head;
		stack = stack->next;
	}
}