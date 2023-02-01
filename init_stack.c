#include "push_swap.h"

static void	index_queue(t_stack *sa, int stack_len)
{
	t_stack		*sa_aux;
	long int	index_number;

	index_number = stack_len;
	sa_aux = sa;
	while (sa != NULL)
	{
		while (sa_aux != NULL)
		{
			if (sa_aux->number > sa->number)
				index_number--;
			sa_aux = sa_aux->next;
		}
		sa->index = index_number;
		index_number = stack_len;
		sa_aux = sa->head;
		sa = sa->next;
	}
}

static void convert_argv_to_int(char *arg, t_stack *stack_a)
{
	t_stack *stack_aux;

	stack_aux = ft_lstlast(stack_a);
	stack_aux->next = ft_lstnew(ft_atoi(arg));
	stack_aux->next->last = stack_aux;
	stack_aux->next->head = stack_a->head;
}

int	init(t_ps *ps, int argc, char **argv)
{
	int index;
	t_stack *stack_a;
	t_stack *stack_b;

	if (verify_argv(argv) == FALSE)
		return (FALSE);
	index = 1;
	stack_a = ft_lstnew(ft_atoi(argv[index]));
	stack_a->head = stack_a;
	stack_a->last = NULL;
	index++;
	while (index < argc)
		convert_argv_to_int(argv[index++], stack_a);
	stack_b = NULL;
	ps->stack_a = stack_a;
	ps->stack_b = stack_b;
	ps->lst_len = index - 1;
	index_queue(ps->stack_a, ps->lst_len);
	return (TRUE);
}