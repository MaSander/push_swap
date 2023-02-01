#ifndef STRUCT_H
# define STRUCT_H

# include "./push_swap.h"

/**
 * @brief struck para armazenar os numeros que serão ordenados
 */
typedef struct s_stack
{
	long long int		number;
	long long int		index;
	struct s_stack		*head;
	struct s_stack		*last;
	struct s_stack		*next;
}	t_stack;

/**
 * @brief a stack tem o tamanho dos argumentos e a stack A e B
 */
typedef struct s_ps
{
	int				lst_len;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_ps;

#endif