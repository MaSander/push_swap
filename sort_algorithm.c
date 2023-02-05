/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:18:13 by oburato           #+#    #+#             */
/*   Updated: 2023/02/01 15:18:14 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_ps *ps)
{
	t_stack	*aux;

	aux = ps->stack_a;
	while (aux->next)
	{
		if (aux->number < aux->next->number)
			aux = aux->next;
		else
			return (-1);
	}
	return (1);
}

static int	find_smallest_index(t_stack *s)
{
	int	index;

	index = s->index;
	while (s->next)
	{
		if (index > s->next->index)
			index = s->next->index;
		s = s->next;
	}
	return (index);
}

t_stack	*sort_three(t_stack *s)
{
	int	first;
	int	second;
	int	third;

	if (verify_lst_is_sorted(s) == TRUE)
		return (s);
	first = s->number;
	second = s->next->number;
	third = s->next->next->number;
	if ((first > second && second < third && third > first)
		|| (first > second && first > third && second > third)
		|| (first < second && first < third && second > third))
		ft_swap(s, 'a');
	first = s->number;
	second = s->next->number;
	third = s->next->next->number;
	if (first < second && first > third && second > third)
		s = ft_reverse_rotate(s, 'a');
	if (first > second && first > third && second < third)
		s = ft_rotate(s, 'a');
	return (s);
}

void	sort_five(t_ps *ps)
{
	int	lower_index;

	while (ps->stack_a)
	{
		if (verify_lst_is_sorted(ps->stack_a) == TRUE)
			break ;
		lower_index = find_smallest_index(ps->stack_a);
		while (ps->stack_a->index != lower_index)
			ps->stack_a = ft_rotate(ps->stack_a, 'a');
		ft_push(&ps->stack_a, &ps->stack_b, 'b');
	}
	while (ps->stack_b)
		ft_push(&ps->stack_b, &ps->stack_a, 'a');
}

int	ft_radix(t_ps *ps)
{
	long unsigned int	index_bit;
	int					index;

	index_bit = 0;
	while (index_bit < 16UL)
	{
		index = 0;
		while (index++ < ps->lst_len)
		{
			if (verify_lst_is_sorted(ps->stack_a) == TRUE)
				break ;
			if ((ps->stack_a->index >> index_bit) & 0b00000001)
				ps->stack_a = ft_rotate(ps->stack_a, 'a');
			else
				ft_push(&ps->stack_a, &ps->stack_b, 'b');
		}
		while (ps->stack_b)
			ft_push(&ps->stack_b, &ps->stack_a, 'a');
		if (verify_lst_is_sorted(ps->stack_a) == TRUE)
			break ;
		index_bit++;
	}
	return (0);
}
