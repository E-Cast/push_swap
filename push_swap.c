#include "push_swap.h"

static void	make_list(char **argv, t_stack **stack_a)
{
	// to be implemented

	// placeholder code
	if (stack_a && *stack_a && argv[1])
		(*stack_a)->value = 42;
}

static void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	// to be implemented

	// placeholder code
	if (stack_a && *stack_a)
		(*stack_a)->value = 42;
	if (stack_b && *stack_b)
		(*stack_b)->value = 42;
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc == 1)
		return (EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	check_args(argv);				// to be implemented
	make_list(argv, stack_a);		// to be implemented
	algorithm(stack_a, stack_b);	// to be implemented
	printf("success!\n");			// temporary
	terminate(stack_a, stack_b, EXIT_SUCCESS);
}
