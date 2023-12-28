#include "../push_swap.h"

int	ft_atoi(char *str)
{
	size_t	i;
	int		sign;
	int		num;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	num = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - 48) * sign;
		i++;
	}
	return (num);
}


void	make_stack(char **argv, t_stack **stack)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 || argv[i][j - 1] == ' ')
			{
				node_addb(stack, node_create(ft_atoi(&argv[i][j]), stack));
				check_dup(stack, node_last(stack));
			}
			j++;
		}
		i++;
	}
}
