#include "../push_swap.h"

static t_stack	*find_biggest(t_stack **stack)
{
	t_stack	*current;
	t_stack	*biggest;

	current = *stack;
	biggest = current;
	while (current)
	{
		if (current->index > biggest->index)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

int	get_sorted_position(t_stack **stack, int minimum)
{
	t_stack	*current;
	t_stack	*smallest;

	if (!stack)
		return (0);
	current = *stack;
	smallest = NULL;
	if (find_biggest(stack)->index < minimum)
		return (get_position(stack, find_biggest(stack)));
	while (current != NULL)
	{
		if (smallest == NULL && current->index > minimum)
			smallest = current;
		else if (current->index > minimum && current->index < smallest->index)
			smallest = current;
		current = current->next;
	}
	return (get_position(stack, smallest) + 1);
	// what if it's the biggest?
}

// int	get_sorted_position(t_stack **stack, t_stack *node)
// {
// 	t_stack	*prev;
// 	t_stack	*next;
// 	int		position;

// 	prev = node_get(stack, -1);
// 	next = *stack;
// 	position = 1;
// 	while (next != NULL)
// 	{
// 		if (prev->index > node->index && next->index < node->index)
// 			break ;
// 		prev = next;
// 		next = next->next;
// 		position++;
// 	}
// 	return (position);
// }
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
	pb(stack_a, stack_b);
	if ((*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b);
	if ((*stack_b)->index < (*stack_b)->next->index)
		sb(stack_b);
	while (*stack_a != NULL)
	{
		path = get_cheapest(stack_a, stack_b);
		execute_path(stack_a, stack_b, path);
		pb(stack_a, stack_b);
	}
}
