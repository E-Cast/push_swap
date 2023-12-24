#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 1)
		return (1);
	stack_a = args_to_list(argv);

	print_list(&stack_a);
}
