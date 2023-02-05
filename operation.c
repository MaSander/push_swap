/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:18:31 by oburato           #+#    #+#             */
/*   Updated: 2023/02/01 15:53:14 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_sub, t_stack **stack_add, char stack_name)
{
	t_stack	*added;
	t_stack	*subtracted;

	if (!*stack_sub)
		return ;
	added = *stack_add;
	subtracted = *stack_sub;
	*stack_sub = subtracted->next;
	subtracted->last = 0;
	*stack_add = subtracted;
	if (added)
	{
		subtracted->next = added;
		added->last = subtracted;
	}
	else
	{
		subtracted->next = NULL;
		subtracted->last = NULL;
	}
	ft_putstr_fd("p", 1);
	ft_putchar_fd(stack_name, 1);
	ft_putstr_fd("\n", 1);
}

t_stack	*ft_reverse_rotate(t_stack *stack, char stack_name)
{
	t_stack	*new_first;

	new_first = ft_lstlast(stack);
	new_first->last->next = 0;
	new_first->next = stack;
	new_first->last = 0;
	stack->last = new_first;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack_name, 1);
	ft_putstr_fd("\n", 1);
	return (new_first);
}

t_stack	*ft_rotate(t_stack *stack, char stack_name)
{
	t_stack	*last;
	t_stack	*new_first;

	new_first = stack->next;
	last = ft_lstlast(stack);
	new_first->last = 0;
	stack->next = 0;
	last->next = stack;
	ft_putstr_fd("r", 1);
	ft_putchar_fd(stack_name, 1);
	ft_putstr_fd("\n", 1);
	return (new_first);
}

void	ft_swap(t_stack *stack, char stack_name)
{
	int	aux_number;
	int	aux_index;

	aux_number = stack->number;
	aux_index = stack->index;
	stack->number = stack->next->number;
	stack->index = stack->next->index;
	stack->next->number = aux_number;
	stack->next->index = aux_index;
	ft_putstr_fd("s", 1);
	ft_putchar_fd(stack_name, 1);
	ft_putstr_fd("\n", 1);
}
