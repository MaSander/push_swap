#include "push_swap.h"
#include <stdio.h>

void index_queue(t_stack *sa, int stack_len)
{
	t_stack	*sa_aux;
	int		index_number;

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
