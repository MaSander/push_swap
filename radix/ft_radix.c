#include "radix.h"

int	ft_radix(t_ps *ps)
{
	long unsigned int	index_bit;
	int					index;

	index_bit = 0;
	while (index_bit < 16UL)
	{
		index = 0;
		while (index++ < ps->lst_len)
		{
			if (verify_lst_is_sorted(ps->stack_a) == TRUE)
				break ;
			if (((ps->stack_a->index >> index_bit) & 1) == 1)
				ps->stack_a = ft_rotate(ps->stack_a, 'a');
			else
				ft_push(&ps->stack_a, &ps->stack_b, 'b');
		}
		while (ps->stack_b)
			ft_push(&ps->stack_b, &ps->stack_a, 'a');
		if (verify_lst_is_sorted(ps->stack_a) == TRUE)
			break ;
		index_bit++;
	}
	return (0);
}
