#include "utils.h"

t_stack	*ft_lstnew(long int number)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->number = number;
	node->next = NULL;
	node->index = 0;
	return (node);
}
