#include "push_swap.h"
#include <stdio.h>

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

	if(init(&ps, argc, argv) == 0)
		return (-1);

	printf("\n%d\n", ps.lst_len);
	ft_lstprint(ps.stack_a);

	if(ps.lst_len == 3)
		sort_three(&ps);
	if(ps.lst_len == 5)
		sort_five(&ps);

	ft_lstprint(ps.stack_a);

	ft_lstclear(&ps.stack_a);
	ft_lstclear(&ps.stack_b);
	return (0);
}
