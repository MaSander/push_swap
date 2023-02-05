/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:18:40 by oburato           #+#    #+#             */
/*   Updated: 2023/02/01 15:18:41 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(long int number)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->number = number;
	node->next = NULL;
	node->index = 0;
	return (node);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next)
		lst = ft_lstlast(lst->next);
	return (lst);
}
