#include "../push_swap.h"

static int	get_sorted_position(t_stack **stack, t_stack *node)
{
	t_stack	*index;
	int		position;

	index = *stack;
	position = 1;
	while (index != NULL)
	{
		if (node->index > index->index)
			return (position);
		index = index->next;
		position++;
	}
	return (position);
}

static int	get_cost(t_stack **stack_a, t_stack **stack_b, t_stack *node)
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

int	get_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_node;
	int		index;
	int		position;
	int		cheapest;

	current_node = *stack_a;
	index = 1;
	position = 1;
	cheapest = get_cost(stack_a, stack_b, current_node);
	while (current_node != NULL)
	{
		if (cheapest > get_cost(stack_a, stack_b, current_node))
		{
			cheapest = get_cost(stack_a, stack_b, current_node);
			position = index;
		}
		current_node = current_node->next;
		index++;
	}
	return (position);
}
// to do next:
// find cheapest (find cost on an entire stack)
// execute cheapest
// run execute cheapest on stack while stack > 3
// sort three on stack