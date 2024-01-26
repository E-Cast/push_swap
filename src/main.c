#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		blk_len;

	if (argc == 1)
		return (0);
	check_args(argv);
	stack_a = NULL;
	stack_b = NULL;
	make_stack(argv, &stack_a);
	sort_check(&stack_a);
	index_stack(&stack_a);
	sort(&stack_a, &stack_b);
	sort_check(&stack_a);
	terminate(&stack_a, NULL, EXIT_FAILURE);
}
