#include "push_swap.h"

void	print_list(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*cursor_1;
	t_stack	*cursor_2;

	cursor_1 = *stack_1;
	cursor_2 = *stack_2;
	printf("---------\na	b\n\n");
	while (cursor_1 && cursor_2)
	{
		printf("%i	%i\n", cursor_1->value, cursor_2->value);
		cursor_1 = cursor_1->next;
		cursor_2 = cursor_2->next;
	}
	while (cursor_1)
	{
		printf("%i\n", cursor_1->value);
		cursor_1 = cursor_1->next;
	}
	while (cursor_2)
	{
		printf("	%i\n", cursor_2->value);
		cursor_2 = cursor_2->next;
	}
	printf("---------\n");
	return ;
}

void	sort_check(t_stack **stack)
{
	t_stack	*current;
	t_stack *last_node;

	if (!stack || !*stack)
		return ;
	current = (*stack)->next;
	last_node = NULL;
	while (current)
	{
		if (last_node && last_node->value > current->value)
			return ;
		last_node = current;
		current = current->next;
	}
	terminate(stack, NULL, EXIT_SUCCESS);
}

int	is_indexed(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		if (current->index == 0)
			return (0);
		current = current->next;
	}
	return (1);
}

void	index_list(t_stack **stack)
{
	t_stack *current;
	t_stack *smallest;
	int 	i;

	i = 1;
	while (!is_indexed(stack))
	{
		current = *stack;
		while (current && current->index != 0)
			current = current->next;
		smallest = current;
		while (current)
		{
			if (current->index == 0 && current->value < smallest->value)
				smallest = current;
			current = current->next;
		}
		smallest->index = i++;
	}
}

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
	if (get_length(&stack_a) == 1)
		terminate(&stack_a, NULL, EXIT_SUCCESS);
	sort_check(&stack_a);
	// if (get_length(&stack_a) == 3)
	// {
	// 	three_sort(&stack_a);
	// 	terminate(&stack_a, NULL, EXIT_SUCCESS);
	// }
	index_list(&stack_a);
	// print_index(&stack_a);
	algorithm(&stack_a, &stack_b);
	terminate(&stack_a, &stack_b, EXIT_SUCCESS);
}
