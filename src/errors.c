#include "../push_swap.h"

/*Check if the number currently in the form of a string would cause an 
	overflow or underflow once converted to an int.*/
static void	check_size(char	*str, const char *max)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 10)
		terminate(NULL, NULL, EXIT_FAILURE);
	if (i < 10)
		return ;
	i = 0;
	while (i < 10)
	{
		if (str[i] > max[i])
			terminate(NULL, NULL, EXIT_FAILURE);
		if (str[i] < max[i])
			return ;
		i++;
	}
}

/*Check if the specified character inside the string received as 
	argument is valid.*/
static void	check_char(char *str, size_t i)
{
	int	j;

	if (str[i] == '-' && i != 0 && str[i - 1] != ' ')
		terminate(NULL, NULL, EXIT_FAILURE);
	if (str[i] == '-' && !(str[i + 1] >= '1' && str[i + 1] <= '9'))
		terminate(NULL, NULL, EXIT_FAILURE);
	if (str[i] == '0' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (i == 0)
			terminate(NULL, NULL, EXIT_FAILURE);
		if (str[i - 1] == ' ' || str[i - 1] == '-')
			terminate(NULL, NULL, EXIT_FAILURE);
	}
	if (str[i] == ' ' && (i == 0 || str[i + 1] == ' ' || str[i + 1] == '\0'))
		terminate(NULL, NULL, EXIT_FAILURE);
	j = 0;
	while (VALID_CHARS[j] != '\0')
	{
		if (VALID_CHARS[j] == str[i])
			return ;
		j++;
	}
	terminate(NULL, NULL, EXIT_FAILURE);
}

/*Apply the relevant checks on the array of strings received as 
	argument to ensure it is valid.*/
void	check_args(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			terminate(NULL, NULL, EXIT_FAILURE);
		j = 0;
		while (argv[i][j])
		{
			check_char(argv[i], j);
			if ((j == 0 || argv[i][j - 1] == ' '))
			{
				if (argv[i][j] == '-')
					check_size(&argv[i][j + 1], INT_MIN);
				else
					check_size(&argv[i][j], INT_MAX);
			}
			j++;
		}
		i++;
	}
}

/*check if there is another node in stack with the same value as the one 
	received as argument.*/
void	check_dup(t_stack **stack, t_stack *node)
{
	t_stack	*current_node;

	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node != node && current_node->value == node->value)
			terminate(stack, NULL, EXIT_FAILURE);
		current_node = current_node->next;
	}
}
