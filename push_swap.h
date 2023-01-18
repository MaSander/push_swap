#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "struct.h"
# include "./utils/utils.h"
# include "./operations/operation.h"

int		init(t_ps *ps, int argc, char **argv);
t_stack	*sort_three(t_stack *s);
void	index_queue(t_stack *sa, int satck_len);
void	sort_five(t_ps *ps);

#endif