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

t_stack	*find_smallest(t_stack **stack_b, int min)
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

int	compare_distance(int b_dist, int s_dist)
{
	if (b_dist < 0)
		b_dist *= -1;
	if (s_dist < 0)
		s_dist *= -1;
	if (s_dist < b_dist)
		return (0);
	return (1);
}
void	final_sort(t_stack **stack_a, t_stack **stack_b, int todo, int blk_len)
{
	int		b_dist;
	int		s_dist;

	todo -= blk_len;
	while (find_bigger_than(stack_b, todo))
	{
		b_dist = get_position(stack_b, find_biggest(stack_b)) - 1;
		s_dist = get_position(stack_b, find_smallest(stack_b, todo)) - 1;
		if (b_dist >= get_length(stack_b) / 2)
			b_dist = b_dist - (get_length(stack_b));
		if (s_dist >= get_length(stack_b) / 2)
			s_dist = s_dist - (get_length(stack_b));
		if (compare_distance(b_dist, s_dist))
		{
			while (b_dist != 0)
			{
				if (b_dist > 0)
				{
					rb(stack_b);
					b_dist--;
				}
				if (b_dist < 0)
				{
					rrb(stack_b);
					b_dist++;
				}
			}
			pa(stack_a, stack_b);
		}
		else
		{
			while (s_dist != 0)
			{
				if (s_dist > 0)
				{
					rb(stack_b);
					s_dist--;
				}
				if (s_dist < 0)
				{
					rrb(stack_b);
					s_dist++;
				}
			}
			pa(stack_a, stack_b);
			ra(stack_a);
		}
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
