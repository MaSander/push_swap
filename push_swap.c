/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:18:26 by oburato           #+#    #+#             */
/*   Updated: 2023/02/01 15:21:01 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_queue(t_stack *sa, int stack_len)
{
	t_stack		*sa_aux;
	long int	index_number;

	index_number = stack_len;
	sa_aux = sa;
	while (sa != NULL)
	{
		while (sa_aux != NULL)
		{
			if (sa_aux->number > sa->number)
				index_number--;
			sa_aux = sa_aux->next;
		}
		sa->index = index_number;
		index_number = stack_len;
		sa_aux = sa->head;
		sa = sa->next;
	}
}

static void	convert_argv_to_int(char *arg, t_stack *stack_a)
{
	t_stack	*stack_aux;

	stack_aux = ft_lstlast(stack_a);
	stack_aux->next = ft_lstnew(ft_atoi(arg));
	stack_aux->next->last = stack_aux;
	stack_aux->next->head = stack_a->head;
}

static int	init(t_ps *ps, int argc, char **argv)
{
	int		index;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (verify_argv(argv) == FALSE)
		return (FALSE);
	index = 1;
	stack_a = ft_lstnew(ft_atoi(argv[index]));
	stack_a->head = stack_a;
	stack_a->last = NULL;
	index++;
	while (index < argc)
		convert_argv_to_int(argv[index++], stack_a);
	stack_b = NULL;
	ps->stack_a = stack_a;
	ps->stack_b = stack_b;
	ps->lst_len = index - 1;
	index_queue(ps->stack_a, ps->lst_len);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc == 1)
		return (0);
	if (init(&ps, argc, argv) != FALSE)
	{
		if (verify_lst_is_sorted(ps.stack_a) != TRUE)
		{
			if (ps.lst_len == 2)
				ft_swap(ps.stack_a, 'a');
			else if (ps.lst_len == 3)
				ps.stack_a = sort_three(ps.stack_a);
			else if (ps.lst_len <= 5)
				sort_five(&ps);
			else
				ft_radix(&ps);
		}
		ft_lstclear(&ps.stack_a);
		ft_lstclear(&ps.stack_b);
		return (0);
	}
	ft_putstr_fd("Error", 1);
	return (1);
}
