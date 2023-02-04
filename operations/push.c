#include "./operation.h"

void	ft_push(t_stack **stack_sub, t_stack **stack_add, char stack_name)
{
	t_stack	*added;
	t_stack	*subtracted;

	if (!*stack_sub)
		return ;
	added = *stack_add;
	subtracted = *stack_sub;
	*stack_sub = subtracted->next;
	subtracted->last = 0;
	*stack_add = subtracted;
	if (added)
	{
		subtracted->next = added;
		added->last = subtracted;
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
