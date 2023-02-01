#include "radix.h"

int	ft_radix(t_ps *ps)
{
	int index_bit;
	int index;

	index_bit = 0;
	while (index_bit < 8)
	{
		index = 0;
		while (index++ < ps->lst_len)
		{
			if (((ps->stack_a->index >> index_bit) & 1) == 1)
				ps->stack_a = ft_rotate(ps->stack_a, 'a');
			else
				ft_push(&ps->stack_a, &ps->stack_b, 'b');
		}
		while (ps->stack_b)
			ft_push(&ps->stack_b, &ps->stack_a, 'a');
		index_bit++;
	}
	while (ps->stack_a->index < ps->stack_a->next->index)
		ps->stack_a = ft_reverse_rotate(ps->stack_a, 'a');
	ps->stack_a = ft_reverse_rotate(ps->stack_a, 'a');
	return (0);
}
