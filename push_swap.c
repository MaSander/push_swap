#include "push_swap.h"

int	main(int argc, char ** argv)
{
	int index;
	t_stack *stack_a;

	index = 0;
	stack_a = malloc(sizeof(t_stack *));
	(void)stack_a;
	while (index < argc)
	{
		ft_atoi(argv[index++]);
	}
	return (0);
}
