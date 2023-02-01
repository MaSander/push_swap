#include "push_swap.h"

static int	ft_arg_is_digit(char *arg)
{
	if(arg[0] == '-')
		arg++;
	while (*arg)
	{
		if(*arg < '0' || *arg > '9')
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

static int	compare_args(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (TRUE);
		i++;
	}
	if(str1[i] == 0 && str2[i] == 0)
		return (FALSE);
	return (TRUE);
}

int	verify_argv(char **argv)
{
	int index;
	int index_retry;

	index = 1;
	index_retry = 1;
	while (argv[index])
	{
		if(ft_arg_is_digit(argv[index]) == FALSE)
			return (FALSE);
		if(-2147483649L >= ft_atoi(argv[index]) || 2147483648L <= ft_atoi(argv[index]))
			return (FALSE);
		while (index_retry != index)
		{
			if(compare_args(argv[index], argv[index_retry]) == FALSE)
				return (FALSE);
			index_retry++;
		}
		index++;
		index_retry = 1;
	}
	return (TRUE);
}

int	verify_lst_is_sorted(t_stack *s)
{
	while (s->next)
	{
		if(s->number > s->next->number)
			return (FALSE);
		s = s->next;
	}
	return (TRUE);
}

char	**argv_is_grouped(int argc, char **argv)
{
	char	**new_argv;

	new_argv = NULL;
	if(argc == 2)
		new_argv = ft_split(argv[1], ' ');
	return (new_argv);
}
