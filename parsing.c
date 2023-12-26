#include "push_swap.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		num;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - 48) * sign;
		i++;
	}
	return (num);
}

t_stack	*args_to_list(char **argv)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	i = 1;
	stack = NULL;
	new_node = NULL;
	while (argv[i] != NULL)
	{
		new_node = node_create(ft_atoi(argv[i]));
		node_addb(&stack, new_node);
		i++;
	}
	return (stack);
}
