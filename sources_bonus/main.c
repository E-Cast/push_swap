#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	check_args(argv);
	stack_a = NULL;
	stack_b = NULL;
	(void) stack_b;
	(void) argv;
	make_stack(argv, &stack_a);
	while (stack_a != NULL)
	{
		printf("%i\n", stack_a->value);
		stack_a = stack_a->next;
	}
	read(STDIN_FILENO,);
	// take input and process it
}
