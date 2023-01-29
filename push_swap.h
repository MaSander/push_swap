#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

#        include <stdio.h>

# define TRUE 1
# define FALSE 0

# include "struct.h"
# include "./utils/utils.h"
# include "./operations/operation.h"
# include "./radix/radix.h"

void			ft_lstprint(t_stack *lst);

int		init(t_ps *ps, int argc, char **argv);
t_stack	*sort_three(t_stack *s);
void	index_queue(t_stack *sa, int satck_len);
void	sort_five(t_ps *ps);
void	insert_sort(t_ps *ps);
/**
 * @file verify.c
 * @brief Verifica se dentro do argv tem algum numero repetido, esses tem que ser numeros.
 * @return @c TRUE caso encontre um numero repetido e @c FALSE caso não encontre
 */
int		verify_argv(char **argv);

#endif