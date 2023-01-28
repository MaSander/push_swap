#ifndef STRUCT_H
# define STRUCT_H

# include "./push_swap.h"

/**
 * @brief a stack tem number que representa o argumento que vem por parametro e index a representação dele em um index
 */
typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*head;
	struct s_stack	*last;
	struct s_stack	*next;
}	t_stack;

/**
 * @brief a stack tem o tamanho dos argumentos e a stack A e B
 */
typedef struct s_ps
{
	int				lst_len;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
} t_ps;

#endif