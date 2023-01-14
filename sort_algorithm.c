#include "push_swap.h"

t_stack	*sort_three(t_stack *s)
{ 
	int	first;
	int	second;
	int	third;

	first = s->number;
	second = s->next->number;
	third = s->next->next->number;
	if ((first > second && second < third && third > first)
		|| (first > second && first > third && second > third)
		|| (first < second && first < third && second > third))
		ft_swap(s, 'a');
	first = s->number;
	second = s->next->number;
	third = s->next->next->number;
	if (first < second && first > third && second > third)
	 	s = ft_reverse_rotate(s, 'a');
	if (first > second && first < third && second < third)
	 	s = ft_rotate(s, 'a');
	return (s);
}

void sort_five(t_ps  *ps)
{
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
}
