#include "push_swap.h"

#define RA 1
#define RRA 2
#include <stdio.h>

typedef struct s_report {
    int moves;
    int action;
} t_report;

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

long long find_smallest_than(t_stack *s, long long ref)
{
	long long	index;

	index = 0;
	while (s)
	{
		if (s->index < ref && s->index > index)
			index = s->index;
		s = s->next;
	}
	return (index);
}

t_report	*calculate_rotate(t_stack *s, long long target)
{
	long long	after;
	int			s_size;
	t_report	*report;
	int i;

	i = 0;
	report = malloc(sizeof(t_report));
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
    report->moves = i;
    if (i > s_size)
		report->moves = i - s_size;
	if (i > (s_size / 2) && i < s_size)
	{
		report->action = RRA;
		i = i - s_size;
	}
	return (report);
}

/*
    o proximo numero (index + 1) precisa estar em cima
    se for 5 (proximo = 1)
    se o proximo não estiver na stack_a proximo index + 2
    se (index + 2) = 6, index = 2 
*/

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
		printf("\nr:%d\n", rotates->moves);
        while (rotates->moves)
		{
			if (rotates->action == RRA)
				ps->stack_a = ft_reverse_rotate(ps->stack_a, 'a');
			else
				ps->stack_a = ft_rotate(ps->stack_a, 'a');
			rotates->moves--;
		}
        ft_free(rotates);
		ft_push(&ps->stack_b, &ps->stack_a, 'a');	
	}
	while (ps->stack_a->index != 1)
	{
		ps->stack_a = ft_rotate(ps->stack_a, 'a');
	}
}