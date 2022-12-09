#include "utils.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*node;

	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		free(node);
	}
}
