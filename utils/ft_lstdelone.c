#include "utils.h"

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}
