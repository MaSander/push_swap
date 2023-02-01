#include "utils.h"

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_array(char **ptr)
{
	int	len;

	len = 0;
	while (ptr[len])
	{
		ft_free(ptr[len]);
		len++;
	}
	ft_free(ptr);
}

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

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}
