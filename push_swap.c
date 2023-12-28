#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	check_args(argv);
	make_stack(argv, &stack_a);
	algorithm(&stack_a, &stack_b);	// to be implemented
	terminate(&stack_a, &stack_b, EXIT_SUCCESS);
}
