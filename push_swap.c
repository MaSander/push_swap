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
		printf("(%d)->", node->number);
	}
	printf("\n");
}

void execute_rotates_report(t_report *report, t_ps *ps)
{
	while (report->moves)
	{
		if(report->action == RA)
			ft_rotate(ps->stack_a, 'a');
		if(report->action == RB)
			ft_rotate(ps->stack_b, 'b');
		if(report->action == RRA)
			ft_reverse_rotate(ps->stack_a, 'a');
		if(report->action == RRB)
			ft_reverse_rotate(ps->stack_b, 'b');
		report->moves = report->moves - 1;
	}
}

int	main(int argc, char **argv)
{
	t_ps ps;
	// t_stack *aux;

	// aux = 0;
	if (init(&ps, argc, argv) >= 0)
	{
		index_queue(ps.stack_a, ps.lst_len);

		if(ps.lst_len <= 3)
			ps.stack_a = sort_three(ps.stack_a);
		else if(ps.lst_len <= 5)
			sort_five(&ps);
		// ft_lstprint(ps.stack_a);
		insert_sort(&ps);
		// ft_lstprint(ps.stack_a);
		ft_lstclear(&ps.stack_a);
		ft_lstclear(&ps.stack_b);
		return (0);
	}
	return (-1);
}
