#include "../push_swap.h"

int	get_length(t_stack **stack)
{
	t_stack	*cursor;
	int		i;

	if (!stack || !*stack)
		return (0);
	cursor = *stack;
	i = 0;
	while (cursor)
	{
		cursor = cursor->next;
		i++;
	}
	return (i);
}

// void	second_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*index;
// 	int		biggest;
// 	int		position;
// 	int		i;

// 	while ((*stack_b)->next)
// 	{
// 		index = *stack_b;
// 		biggest = index->index;
// 		position = 0;
// 		i = 0;
// 		while (index != NULL)
// 		{
// 			if (biggest < index->index)
// 			{
// 				biggest = index->index;
// 				position = i;
// 			}
// 			index = index->next;
// 			i++;
// 		}
// 		if (position <= get_length(stack_b) / 2)
// 		{
// 			while (position)
// 			{
// 				rb(stack_b);
// 				position--;
// 			}
// 			pa(stack_a, stack_b);
// 		}
// 		else
// 		{
// 			position = get_length(stack_b) - position;
// 			while (position)
// 			{
// 				rrb(stack_b);
// 				position--;
// 			}
// 			pa(stack_a, stack_b);
// 		}
// 	}
// 	pa(stack_a, stack_b);
// }

int	find_bigger_than(t_stack **stack, int index)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = *stack;
	while (current != NULL)
	{
		if (current->index >= index)
			return (1);
		current = current->next;
	}
	return (0);
}

t_stack	*find_biggest(t_stack **stack)
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

int	get_position(t_stack **stack, t_stack *node)
{
	t_stack	*current;
	int		position;

	current = *stack;
	position = 1;
	while (current && current != node)
	{
		current = current->next;
		position++;
	}
	return (position);
}

t_stack	*get_smallest(t_stack **stack_b, int min)
{
	t_stack	*current;
	t_stack	*smallest;

	current = *stack_b;
	smallest = NULL;
	while (current)
	{
		if (smallest == NULL && current->index >= min)
			smallest = current;
		if (smallest && current->index >= min && smallest->index > current->index)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

void	final_sort(t_stack **stack_a, t_stack **stack_b, int todo, int blk_len)
{
	t_stack	*biggest;
	int		distance;

	todo -= blk_len;
	while (find_bigger_than(stack_b, todo))
	{
		biggest = find_biggest(stack_b);
		distance = get_position(stack_b, biggest);
		if (distance >= get_length(stack_b) / 2)
			distance = distance - (get_length(stack_b) + 1);
		while (*stack_b && *stack_b != biggest)
		{
			// printf("len:%i\ndist:%i\nfirst:%i\nbiggest:%i\n", get_length(stack_b), distance, (*stack_b)->index, biggest->index);
			if (*stack_b == get_smallest(stack_b, todo) && *stack_b != biggest)
			{
				pa(stack_a, stack_b);
				ra(stack_a);
				if (distance > 0)
					distance -= 2;
			}
			if (distance > 0)
			{
				rb(stack_b);
				distance--;
			}
			else if (distance < 0)
			{
				rrb(stack_b);
				distance++;
			}
		}
		pa(stack_a, stack_b);
	}
	while (node_get(stack_a, -1) != find_biggest(stack_a))
		rra(stack_a);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	blk_len;

	blk_len = get_length(stack_a) / 7;
	pre_sort(stack_a, stack_b, 0, blk_len);
	while (*stack_b)
		final_sort(stack_a, stack_b, get_length(stack_b), blk_len);
}
