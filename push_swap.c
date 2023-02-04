#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc == 1)
		return (0);
	if (init(&ps, argc, argv) != FALSE)
	{
		if (verify_lst_is_sorted(ps.stack_a) != TRUE)
		{
			if (ps.lst_len == 2)
				ft_swap(ps.stack_a, 'a');
			else if (ps.lst_len == 3)
				ps.stack_a = sort_three(ps.stack_a);
			else if (ps.lst_len <= 5)
				sort_five(&ps);
			else
				ft_radix(&ps);
		}
		ft_lstclear(&ps.stack_a);
		ft_lstclear(&ps.stack_b);
		return (0);
	}
	ft_putstr_fd("Error", 1);
	return (1);
}
