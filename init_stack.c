#include "push_swap.h"

void convert_argv_to_int(char *arg, t_stack *stack_a)
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

	/*
	checar se
	 - tem numero repetido
	 - todos são digitos
	*/

	index = 1;
	//TODO: Validar se não vem em um argumento só
	stack_a = ft_lstnew(ft_atoi(argv[index]));
	stack_a->head = stack_a;
	stack_a->last = NULL;
	index++;
	while (index < argc)
		convert_argv_to_int(argv[index++], stack_a);
	stack_b = ft_lstnew(0);
	ps->stack_a = stack_a;
	ps->stack_b = stack_b;
	ps->lst_len = index - 1;

	return (1);
}