#include "push_swap.h"
#include <stdio.h>

// TODO: remover essa função
void	ft_lstprint(t_stack *lst)
{
	t_stack	*node;

	printf("\n");
	while (lst)
	{
		node = lst;
		lst = lst->next;
		printf("(%d)->", node->number);
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_ps ps;
	// t_stack *aux;

	// aux = 0;
	if (init(&ps, argc, argv) >= 0)
	{
		index_queue(ps.stack_a, ps.lst_len);

		// if(ps.lst_len <= 3)
		// {
		// 	printf("Sort 3");
		// 	ps.stack_a = sort_three(ps.stack_a);
		// }
		// else if(ps.lst_len <= 5)
		// {
		// 	printf("Sort 5");
		// 	sort_five(&ps);
		// }

		ft_lstprint(ps.stack_a);
		// aux = ft_clonelst(ps.stack_a);
		ft_lstprint(ft_clonelst(ps.stack_a));

		ft_lstclear(&ps.stack_a);
		ft_lstclear(&ps.stack_b);
		return (0);
	}
	return (-1);
}
