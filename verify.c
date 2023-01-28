#include "push_swap.h"

static int	ft_numlst(t_stack *lst, int number)
{
	t_stack	*node;

	while (lst)
	{
		node = lst;
		lst = lst->next;
		if (number == node->number)
			return (TRUE);
	}
	return (FALSE);
}

int verify_repet(char **argv)
{
	int index;
	t_stack *stack;

	index = 1;
	stack = NULL;
	while (argv[index])
	{
		if (stack == NULL)
			stack = ft_lstnew(ft_atoi(argv[index]));
		else
		{
			if (ft_numlst(stack, ft_atoi(argv[index])))
			{
				ft_lstclear(&stack);
				return (TRUE);
			}
			ft_lstlast(stack)->next = ft_lstnew(ft_atoi(argv[index]));
		}
		index++;
	}
	ft_lstclear(&stack);
	return (FALSE);
}
