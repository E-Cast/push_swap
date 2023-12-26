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

void	is_char_valid(char chr)
{
	int	i;

	i = 0;
	while (VALID_CHARS[i] != '\0')
	{
		if (VALID_CHARS[i] == chr)
			return ;
		i++;
	}
	printf("Error\n");
	exit(EXIT_FAILURE);
}

void	char_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i] && argv[i][j] != '\0')
		{
			is_char_valid(argv[i][j]);
			j++;
		}
		i++;
	}
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
				node_addb(&stack, node_create(ft_atoi(&argv[i][j])));
				while (argv[i][j] != '\0' && argv[i][j] != ' ')
					j++;
			}
			else
				j++;
		}
		i++;
	}
	return (stack);
}
