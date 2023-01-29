#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

#        include <stdio.h>

# define TRUE 1
# define FALSE 0

# include "struct.h"
# include "verify.h"
# include "./radix/radix.h"
# include "./utils/utils.h"
# include "./operations/operation.h"

void			ft_lstprint(t_stack *lst);

int		init(t_ps *ps, int argc, char **argv);
t_stack	*sort_three(t_stack *s);
void	index_queue(t_stack *sa, int satck_len);
void	sort_five(t_ps *ps);
void	insert_sort(t_ps *ps);

#endif