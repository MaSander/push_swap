#include "push_swap.h"

t_report	*calculate_rotate(t_stack *s, int target)
{
	/* TODO: saber quantas rotações preciso dar para colocar o alvo no lugar

	saber numero mais alto
	saber o numero mais baixo?

	*/
	int count;
	int	front;
	// int	back;

	// back = s->last->index;
	front = s->head->index;
	while (target > front)
	{
		front = s->next->index;
		// back = s->index;
		count++;
	}

	return ;
}

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
	if (first > second && first > third && second < third)
	 	s = ft_rotate(s, 'a');
	return (s);
}

void sort_five(t_ps  *ps)
{
	// t_stack *a;
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
	ft_push(&ps->stack_a, &ps->stack_b, 'b');
	sort_three(ps->stack_a);
	// a = &ps->stack_a_number;
	// if (ps->stack_b->number > a->next->next->number)
	// {
	// 	ft_push(&ps->stack_b, &ps->stack_a, 'a');
	// }
	// if (ps->stack_b->number > a->next->number)
	// {
	// 	// rra pa ra ra
	// }
	// if (ps->stack_b->number > a->number)
	// {
	// 	// ra pa rra

	// }
}
