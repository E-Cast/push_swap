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
	// int		blk_len;

	if (argc == 1)
		return (0);
	check_args(argv);
	stack_a = NULL;
	stack_b = NULL;
	make_stack(argv, &stack_a);
	// sort_check(&stack_a);
	index_stack(&stack_a);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// print_list(&stack_a);
	// print_list(&stack_b);
	// printf("%i\n", get_cheapest(&stack_a, &stack_b));
	sort_check(&stack_a);
	terminate(&stack_a, NULL, EXIT_FAILURE);
}
