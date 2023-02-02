#ifndef STRUCT_H
# define STRUCT_H

# include "./push_swap.h"

# define PB 0
# define PA 1
# define RA 2
# define RB 3
# define RR 4
# define RRA 5
# define RRB 6
# define RRR 7
# define SA 8
# define SB 9
# define SS 10

/**
 * @brief a stack tem number que representa o argumento que vem por parametro e index a representação dele em um index
 */
typedef struct s_stack
{
	long long int			number;
	long long int				index;
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
} t_ps;

typedef struct s_report
{
	int moves;
	int	action;
} t_report;

#endif