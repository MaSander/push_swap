#include "push_swap.h"

t_report	*calculate_rotate(t_stack *s, int target)
{
	/* TODO: saber quantas rotações preciso dar para colocar o alvo no lugar

	saber maior index
	saber menor index

	*/
	int	count;
	int	front;
	// int	back;
	t_report *report;

	report = 0;
	// back = s->last->index;
	front = s->head->index;
	count = 0;
	while (target > front)
	{
		front = s->next->index;
		// back = s->index;
		count++;
	}
	report->moves = count;
	report->action = RA;
	return (report);
}

t_stack	*sort_three(t_stack *s)
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
	first = s->number;
	second = s->next->number;
	third = s->next->next->number;
	if (first < second && first > third && second > third)
		s = ft_reverse_rotate(s, 'a');
	if (first > second && first > third && second < third)
		s = ft_rotate(s, 'a');
	return (s);
}

void	sort_five(t_ps  *ps)
{
	if (verify_lst_is_sorted(ps->stack_a) == TRUE)
		return ;
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
	sort_three(ps->stack_a);
	// TODO: continuar
}
