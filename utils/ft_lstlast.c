#include "utils.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next)
		lst = ft_lstlast(lst->next);
	return (lst);
}
