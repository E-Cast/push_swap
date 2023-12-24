#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*first_node;
	t_stack	*new_node;
	int		i;

	if (argc == 1)
		return (1);
	i = 1;
	first_node = NULL;
	new_node = NULL;
	while (argv[i] != NULL)
	{
		new_node = node_create(ft_atoi(argv[i]));
		node_addb(&first_node, new_node);
		i++;
	}

	sa(&first_node);
	new_node = first_node;
	while (new_node != NULL)
	{
		printf("%i\n", new_node->value);
		new_node = new_node->next;
	}
	return (0);
}
