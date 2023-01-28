#include "utils.h"

int	find_smallest_index(t_stack *s)
{
	int index;

	index = s->index;
	while (s->next)
	{
		if (index > s->next->index)
			index = s->next->index;
		s = s->next;
	}
	return index;
}

int	find_biggest_index(t_stack *s)
{
	int index;

	index = s->index;
	while (s->next)
	{
		if (index < s->next->index)
			index = s->next->index;
		s = s->next;
	}
	return index;
}
