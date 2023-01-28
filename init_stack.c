#include "push_swap.h"

int	ft_numlst(t_stack *lst, int number)
{
	t_stack	*node;

	while (lst)
	{
		node = lst;
		lst = lst->next;
		if (number == node->number)
			return (TRUE);
	}
	return (FALSE);
}

void convert_argv_to_int(char *arg, t_stack *stack_a)
{
	t_stack *stack_aux;


	stack_aux = ft_lstlast(stack_a);
	stack_aux->next = ft_lstnew(ft_atoi(arg));
	stack_aux->next->last = stack_aux;
	stack_aux->next->head = stack_a->head;
}

static int verify_repet(char **argv)
{
	int index;
	t_stack *stack;

	index = 1;
	stack = NULL;
	while (argv[index])
	{
		if (stack == NULL)
			stack = ft_lstnew(ft_atoi(argv[index]));
		else
		{
			if (ft_numlst(stack, ft_atoi(argv[index])))
			{
				ft_lstclear(&stack);
				return (TRUE);
			}
			ft_lstlast(stack)->next = ft_lstnew(ft_atoi(argv[index]));
		}
		index++;
	}
	ft_lstclear(&stack);
	return (FALSE);
}

int	init(t_ps *ps, int argc, char **argv)
{

	int index;
	t_stack *stack_a;
	t_stack *stack_b;

	if (verify_repet(argv))
		return (FALSE);
	// if(verify_equal_or_isdigit(argv) < 0)
	// 	return (-1);

	/*
	checar se
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