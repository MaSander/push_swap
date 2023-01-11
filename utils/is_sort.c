#include "./utils.h"

int	is_sort(t_ps *ps)
{
	t_stack	*aux;

	aux = ps->stack_a;
	while (aux->next)
	{
		if (aux->number < aux->next->number)
			aux = aux->next;
		else
			return (-1);
	}
	return (1);
}
