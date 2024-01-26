#include "../push_swap.h"

static int	get_sorted_position(t_stack **stack, t_stack *node)
{
	t_stack	*next_node;
	int		position;

	next_node = *stack;
	position = 1;
	while (next_node != NULL)
	{
		if (node->value > next_node->value)
			return (position);
		next_node = next_node->next;
		position++;
	}
	return (position);
}

int	find_cost(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int	position;
	int	sorted_pos;
	int	moves;

	position = get_position(stack_a, node);
	moves = 1;
	if (position <= get_length(stack_a) / 2)
		moves += position - 1;
	else if (get_length(stack_a) > 1)
		moves += (get_length(stack_a) + 1) - position;
	sorted_pos = get_sorted_position(stack_b, node);
	if (sorted_pos <= get_length(stack_b) / 2)
		moves += sorted_pos - 1;
	else
		moves += (get_length(stack_b) + 1) - sorted_pos;
	return (moves);
}

