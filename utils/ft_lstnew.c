#include "utils.h"

t_stack	*ft_lstnew(int number)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->number = number;
	node->next = NULL;
	return (node);
}
