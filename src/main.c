#include "../push_swap.h"

void	print_list(t_stack **stack)
{
	t_stack	*current_node;

	current_node = *stack;
	while (current_node != NULL)
	{
		printf("%i\n", current_node->value);
		current_node = current_node->next;
	}
	printf("\b\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
