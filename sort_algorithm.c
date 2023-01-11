#include "push_swap.h"

void sort_three(t_ps *ps)
{
	if(ps->stack_a->number > ps->stack_a->next->number)
		ft_swap(ps->stack_a, 'a');
}

void sort_five(t_ps  *ps)
{
	if(ps->stack_a->number > ps->stack_a->next->number)
		ft_swap(ps->stack_a, 'a');
}
