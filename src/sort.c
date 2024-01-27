#include "../push_swap.h"

int	get_sorted_position(t_stack **stack, t_stack *node)
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

static t_path	get_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_node;
	int		index;
	t_path	cheapest;

	current_node = *stack_a;
	index = 1;
	cheapest = get_path(stack_a, stack_b, current_node);
	while (current_node != NULL)
	{
		if (cheapest.moves > get_path(stack_a, stack_b, current_node).moves)
			cheapest = get_path(stack_a, stack_b, current_node);
		current_node = current_node->next;
		index++;
	}
	return (cheapest);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_path	path;

	pb(stack_a, stack_b);
	while (*stack_a != NULL)
	{
		path = get_cheapest(stack_a, stack_b);
		execute_path(stack_a, stack_b, path);
		pb(stack_a, stack_b);
	}
}
