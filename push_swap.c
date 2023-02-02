#include "push_swap.h"
#include <stdio.h>

/** @warning TODO: remover essa função */
void	ft_lstprint(t_stack *lst)
{
	t_stack	*node;

	printf("\n");
	while (lst)
	{
		node = lst;
		lst = lst->next;
		printf("(%lld)->", node->number);
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_ps ps;

	if (init(&ps, argc, argv) != FALSE)
	{
		index_queue(ps.stack_a, ps.lst_len);

		if(ps.lst_len <= 3)
			ps.stack_a = sort_three(ps.stack_a);
		else if(ps.lst_len <= 5)
			sort_five(&ps);
		else
			ft_radix(&ps);
		ft_lstclear(&ps.stack_a);
		ft_lstclear(&ps.stack_b);
		return (0);
	}
	ft_putstr_fd("Error", 1);
	return (1);
}
