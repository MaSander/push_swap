#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define MAXINT 2147483648L
# define MININT -2147483649L

# include "struct.h"
# include "./utils/utils.h"
# include "./operations/operation.h"
# include "./radix/radix.h"

void	ft_lstprint(t_stack *lst);
int		init(t_ps *ps, int argc, char **argv);
t_stack	*sort_three(t_stack *s);
t_stack	*sort_two(t_stack *s);
void	sort_five(t_ps *ps);
void	insert_sort(t_ps *ps);
int		verify_argv(char **argv);
int		verify_lst_is_sorted(t_stack *s);
char	**argv_is_grouped(int argc, char **argv);

#endif