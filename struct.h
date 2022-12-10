#ifndef STRUCT_H
# define STRUCT_H

# include "./push_swap.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*head;
	struct s_stack	*last;
	struct s_stack	*next;
}	t_stack;

#endif