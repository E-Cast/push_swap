// #include "../push_swap.h"

// static int	find_bigger_than(t_stack **stack, int index)
// {
// 	t_stack	*current;

// 	if (!stack)
// 		return (0);
// 	current = *stack;
// 	while (current != NULL)
// 	{
// 		if (current->index >= index)
// 			return (1);
// 		current = current->next;
// 	}
// 	return (0);
// }

// int	get_position(t_stack **stack, t_stack *node)
// {
// 	t_stack	*current;
// 	int		position;

// 	current = *stack;
// 	position = 1;
// 	while (current && current != node)
// 	{
// 		current = current->next;
// 		position++;
// 	}
// 	return (position);
// }

// static t_stack	*find_biggest(t_stack **stack)
// {
// 	t_stack	*current;
// 	t_stack	*biggest;

// 	current = *stack;
// 	biggest = current;
// 	while (current)
// 	{
// 		if (current->index > biggest->index)
// 			biggest = current;
// 		current = current->next;
// 	}
// 	return (biggest);
// }

// static t_stack	*find_smallest(t_stack **stack_b, int min)
// {
// 	t_stack	*current;
// 	t_stack	*smallest;

// 	current = *stack_b;
// 	smallest = NULL;
// 	while (current)
// 	{
// 		if (smallest == NULL && current->index >= min)
// 			smallest = current;
// 		if (smallest && current->index >= min && smallest->index > current->index)
// 			smallest = current;
// 		current = current->next;
// 	}
// 	return (smallest);
// }

// static int	compare_distance(int b_dist, int s_dist)
// {
// 	if (b_dist < 0)
// 		b_dist *= -1;
// 	if (s_dist < 0)
// 		s_dist *= -1;
// 	if (s_dist < b_dist / 1.5)
// 		return (0);
// 	return (1);
// }

// static int	move_to_node(int distance, t_stack **stack)
// {
// 	if (distance > 0)
// 	{
// 		rb(stack);
// 		return (-1);
// 	}
// 	if (distance < 0)
// 	{
// 		rrb(stack);
// 		return (1);
// 	}
// 	return (0);
// }

// static int	get_distance(t_stack **stack, t_stack *node)
// {
// 	int	distance;

// 	distance = get_position(stack, node) - 1;
// 	if (distance >= get_length(stack) / 2)
// 		distance = distance - (get_length(stack));
// 	return (distance);
// }

// void	final_sort(t_stack **stack_a, t_stack **stack_b, int todo, int blk_len)
// {
// 	int		b_dist;
// 	int		s_dist;

// 	todo -= blk_len;
// 	while (find_bigger_than(stack_b, todo))
// 	{
// 		b_dist = get_distance(stack_b, find_biggest(stack_b));
// 		s_dist = get_distance(stack_b, find_smallest(stack_b, todo));
// 		if (compare_distance(b_dist, s_dist))
// 		{
// 			while (b_dist != 0)
// 				b_dist += move_to_node(b_dist, stack_b);
// 			pa(stack_a, stack_b);
// 		}
// 		else
// 		{
// 			while (s_dist != 0)
// 				s_dist += move_to_node(s_dist, stack_b);
// 			pa(stack_a, stack_b);
// 			ra(stack_a);
// 		}
// 	}
// 	while (node_get(stack_a, -1) != find_biggest(stack_a))
// 		rra(stack_a);
// }

