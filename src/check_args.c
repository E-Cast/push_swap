#include "../push_swap.h"

void	check_char(char *str, size_t i)
{
	int	j;

	if (str[i] == '-' && i != 0 && str[i - 1] != ' ')
		terminate(NULL, NULL, EXIT_FAILURE);
	if (str[i] == '-' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
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
			check_char(argv[i], j++);
		}
		i++;
	}
}
