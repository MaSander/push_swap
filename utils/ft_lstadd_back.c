#include "utils.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (new)
	{
		if (*lst)
		{
			node = ft_lstlast((*lst));
			node->next = new;
		}
		else
			*lst = new;
	}
}
