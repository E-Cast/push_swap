#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*new_node;
	int		i;

	if (argc == 1)
		return (1);
	i = 1;
	stack_a = NULL;
	new_node = NULL;
	while (argv[i] != NULL)
	{
		new_node = node_create(ft_atoi(argv[i]));
		node_addb(&stack_a, new_node);
		i++;
	}

	print_list(&stack_a);
}
