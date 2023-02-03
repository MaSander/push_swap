#include "push_swap.h"

t_report	*calculate_rotate(t_stack *s, long long target)
{
	long long	after;
	int			s_size;
	t_report	*report;
	int i;

	i = 1;
	report = 0;
	s_size = ft_lstsize(s);
	after = find_smallest_than(s, target);
	while (s)
	{
		if (s->index == after)
			break ;
		i++;
		s = s->next;
	}
	report->action = RA;
	if (i > s_size)
		report->moves = i - s_size;
	if (i > (s_size / 2) && i < s_size)
	{
		report->action = RRA;
		i = i - s_size;
	}
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
	t_report	*rotates;

	rotates = 0;
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
	ps->stack_a = order_three(ps->stack_a);
	while (ps->stack_b)
	{
		rotates = calculate_rotate(ps->stack_a, ps->stack_b->index);
		while (rotates->moves)
		{
			if (rotates->action == RRA)
				ps->stack_a = ft_reverse_rotate(ps->stack_a, 'a');
			else
				ps->stack_a = ft_rotate(ps->stack_a, 'a');
			rotates->moves--;
		}
		ft_push(&ps->stack_b, &ps->stack_a, 'b');	
	}
	while (ps->stack_a->index != 1)
	{
		ps->stack_a = ft_rotate(ps->stack_a, 'a');
	}
}
