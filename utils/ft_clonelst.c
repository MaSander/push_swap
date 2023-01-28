#include "utils.h"

t_stack	*ft_clonelst(t_stack *lst)
{
	t_stack *clone;

	clone = ft_lstnew(lst->number);
	while (lst->next)
	{
		ft_lstlast(clone)->next = ft_lstnew(lst->next->number);
		lst = lst->next;
	}
	return (clone);
}
