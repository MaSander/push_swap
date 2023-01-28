#include "push_swap.h"

static void put_smaller_on_top(t_stack *s, char stack)
{
	int lower_index;

	lower_index = find_smallest_index(s);
	while (s->index != lower_index)
	{
		ft_rotate(s, stack);
	}
}

void insert_sort(t_ps *ps)
{
	while (ps->stack_a)
	{
		put_smaller_on_top(ps->stack_a, 'a');
		ft_push(&ps->stack_a, &ps->stack_b, 'b');
	}
	while (ps->stack_b)
	{
		ft_push(&ps->stack_b, &ps->stack_a, 'a');
	}
}
