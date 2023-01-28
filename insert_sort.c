#include "push_swap.h"

void insert_sort(t_ps *ps)
{
	int lower_index;

	while (ps->stack_a)
	{
		lower_index = find_smallest_index(ps->stack_a);
		while (ps->stack_a->index != lower_index)
		{
			ps->stack_a = ft_rotate(ps->stack_a, 'a');
		}
		ft_push(&ps->stack_a, &ps->stack_b, 'b');
	}
	while (ps->stack_b)
	{
		ft_push(&ps->stack_b, &ps->stack_a, 'a');
	}
}
