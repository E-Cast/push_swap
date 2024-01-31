#include "../push_swap.h"

t_stack	*find_biggest(t_stack **stack)
{
	t_stack	*current;
	t_stack	*biggest;

	current = *stack;
	biggest = current;
	while (current)
	{
		if (current->value > biggest->value)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

int	get_sorted_position(t_stack **stack, int node)
{
	t_stack	*current;
	t_stack	*smallest;

	if (!stack)
		return (0);
	current = *stack;
	smallest = NULL;
	if (find_biggest(stack)->value < node)
		return (get_position(stack, find_biggest(stack)) + 1);
	while (current != NULL)
	{
		if (smallest == NULL && current->value > node)
			smallest = current;
		else if (current->value > node && current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (get_position(stack, smallest));
}

static t_path	get_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_node;
	t_path	cheapest;
	t_path	new_path;

	current_node = *stack_b;
	cheapest = get_path(stack_a, stack_b, current_node);
	while (current_node != NULL)
	{
		new_path = get_path(stack_a, stack_b, current_node);
		if (cheapest.moves > new_path.moves)
			cheapest = new_path;
		current_node = current_node->next;
		if (cheapest.moves == 1)
			return (cheapest);
	}
	return (cheapest);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_path	path;
	int		biggest;

	pb(stack_a, stack_b, get_length(stack_a) - 3);
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		path = get_cheapest(stack_a, stack_b);
		execute_path(stack_a, stack_b, path);
		pa(stack_a, stack_b, 1);
	}
	biggest = get_position(stack_a, find_biggest(stack_a));
	if (biggest < get_length(stack_a) / 2)
		ra(stack_a, biggest);
	else
		rra(stack_a, (get_length(stack_a)) - biggest);
}
