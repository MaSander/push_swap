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
	if (init(&ps, argc, argv) >= 0)
	{
		index_queue(ps.stack_a, ps.lst_len);
	
		t_stack *aux;
		aux = ps.stack_a;
		
		while (aux)
		{
			printf("\n| %d   ->   %d  |\n", aux->index, aux->number);
			aux = aux->next;
		}
		
		
		if(ps.lst_len == 3)
			ps.stack_a = sort_three(ps.stack_a);
		if(ps.lst_len == 5)
			sort_five(&ps);
		ft_lstclear(&ps.stack_a);
		ft_lstclear(&ps.stack_b);
		return (0);
	}
	return (-1);
}
