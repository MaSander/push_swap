#include "push_swap.h"

// static void put_smaller_on_top(t_stack *s, char stack)
// {
// 	int lower_index;

// 	lower_index = find_smallest_index(s);
// 	while (s->index != lower_index)
// 	{
// 		s = ft_rotate(s, stack);
// 	}
// }

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
		ft_lstprint(ps->stack_b);
		ft_push(&ps->stack_a, &ps->stack_b, 'b');
	}
	ft_lstprint(ps->stack_b);
	while (ps->stack_b)
	{
		ft_push(&ps->stack_b, &ps->stack_a, 'a');
	}
}
