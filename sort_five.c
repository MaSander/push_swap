#include "push_swap.h"

#define RA 1
#define RRA 2
#include <stdio.h>

/*
    o proximo numero (index + 1) precisa estar em cima
    se for 5 (proximo = 1)
    se o proximo não estiver na stack_a proximo index + 2
    se (index + 2) = 6, index = 2
*/

void	ft_lstprint(t_stack *lst)
{
	t_stack	*node;

	printf("\n");
	while (lst)
	{
		node = lst;
		lst = lst->next;
		printf("(%lld)->", node->number);
	}
	printf("\n");
}


t_stack	*order_three(t_stack *s)
{
	int	first;
	int	second;
	int	third;

	if (verify_lst_is_sorted(s) == TRUE)
		return (s);
	first = s->number;
	second = s->next->number;
	third = s->next->next->number;
	if ((first > second && second < third && third > first)
		|| (first > second && first > third && second > third)
		|| (first < second && first < third && second > third))
		ft_swap(s, 'a');
	return (s);
}

void	sort_five(t_ps  *ps)
{
	int integer;

	integer = 0;
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
	ps->stack_a = order_three(ps->stack_a);
	while (ps->stack_b)
	{
		integer = ps->stack_b->index + 1;
		if (ps->stack_b->next)
		if (integer == ps->stack_b->next->index)
			integer++;
		if (integer == 6)
			integer = 1;
		if (ps->stack_b->next)
		if (integer == ps->stack_b->next->index)
			integer++;
		while (ps->stack_a->index != integer)
		{
			ps->stack_a = ft_rotate(ps->stack_a, 'a');
			// printf("index(%lld) integer(%d)\n", ps->stack_a->index, integer);
		}
		ft_push(&ps->stack_b, &ps->stack_a, 'a');
	}
	while (ps->stack_a->index != 1)
		ps->stack_a = ft_rotate(ps->stack_a, 'a');
	// ft_lstprint(ps->stack_a);
}
