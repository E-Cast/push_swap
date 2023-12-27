#include "../push_swap.h"
#include <limits.h>

void	size_check(char	*str, const char *max, t_stack **stack)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 10)
		terminate(stack, NULL);
	if (i < 10)
		return ;
	i = 0;
	while (i < 10)
	{
		if (str[i] > max[i])
			terminate(stack, NULL);
		if (str[i] < max[i])
			return ;
		i++;
	}
}

int	str_to_int(const char *str)
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
	}
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - 48) * sign;
		i++;
	}
	return (num);
}

void	char_check(char *chr, t_stack **stack)
{
	int	i;

	i = 0;
	while (VALID_CHARS[i] != '\0')
	{
		if (VALID_CHARS[i] == chr[0])
			return ;
		if ((chr[0] == '+' || chr[0] == '-') && chr[1] >= '0' && chr[1] <= '9')
			return ;
		i++;
	}
	terminate(stack, NULL);
}

t_stack	*args_to_list(char **argv, t_stack *stack)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i] && argv[i][j] != '\0')
		{
			if (argv[i][j] != ' ')
			{
				node_addb(&stack, node_create(str_to_int(&argv[i][j]), &stack));
				while (argv[i][j] != '\0' && argv[i][j] != ' ')
					is_char_valid(&argv[i][j++], &stack);
			}
			else
				is_char_valid(&argv[i][j++], &stack);
		}
		i++;
	}
	return (stack);
}
