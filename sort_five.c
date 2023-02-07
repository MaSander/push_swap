#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

static int	find_smallest_than(t_stack *s, int target)
{
	int	index;

	index = s->index;
	while (s->next)
	{
		if (index > s->next->index && s->next->index > target)
			index = s->next->index;
		s = s->next;
	}
	return (index);
}

int	calculate_rotate(t_stack *s, long long target)
{
	long long	after;
	int i;

	i = 1;
	after = find_smallest_than(s, target);
	while (s)
	{
		if (s->index == after)
			break ;
		i++;
		s = s->next;
	}
	return (i);
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
	int rotates;
	
    ft_push(&ps->stack_a, &ps->stack_b, 'b');
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
	ps->stack_a = order_three(ps->stack_a);
	while (ps->stack_b)
	{
		rotates = calculate_rotate(ps->stack_a, ps->stack_b->index);
		while (rotates)
		{
            ps->stack_a = ft_rotate(ps->stack_a, 'a');
			rotates--;
		}
		ft_push(&ps->stack_b, &ps->stack_a, 'b');	
	}
	while (ps->stack_a->index != 1)
	{
		ps->stack_a = ft_rotate(ps->stack_a, 'a');
	}
}