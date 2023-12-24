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

void	print_list(t_stack **first_node)
{
	t_stack	*new_node;

	new_node = *first_node;
	while (new_node != NULL)
	{
		printf("%i\n", new_node->value);
		new_node = new_node->next;
	}

	return ;
}
