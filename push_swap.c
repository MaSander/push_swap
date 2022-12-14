#include "push_swap.h"
#include <stdio.h>

void	ft_lstprint(t_stack *lst)
{
	t_stack	*node;

	while (lst)
	{
		node = lst;
		lst = lst->next;
		printf("(%d)->", node->number);
	}
}

void convert_argv_to_int(char *arg, t_stack *stack_a)
{
	t_stack *stack_aux;


	stack_aux = ft_lstlast(stack_a);
	stack_aux->next = ft_lstnew(ft_atoi(arg));
	stack_aux->next->last = stack_aux;
	stack_aux->next->head = stack_a->head;
}

int	main(int argc, char ** argv)
{
	int index;
	t_stack *stack_a;

	index = 1;
	stack_a = ft_lstnew(ft_atoi(argv[index]));
	stack_a->head = stack_a;
	stack_a->last = NULL;
	index++;
	while (index < argc)
		convert_argv_to_int(argv[index++], stack_a);
	ft_lstprint(stack_a);
	printf("\n");
	stack_a = ft_rotate(stack_a, 'a');
	ft_lstprint(stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
