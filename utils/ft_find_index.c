#include "utils.h"

// TODO: Deletar se não usar
int	find_smallest_index(t_stack *s)
{
	int	index;

	index = s->index;
	while (s->next)
	{
		if (index > s->next->index)
			index = s->next->index;
		s = s->next;
	}
	return (index);
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

long long	find_biggest_than(t_stack *s, long long ref)
{
	long long	index;

	index = 0;
	while (s)
	{
		if (s->index > ref && (index == 0 || s->index < index))
			index = s->index;
		s = s->next;
	}
	if (index == 0)
		index = find_smallest_index(s);
	return (index);
}