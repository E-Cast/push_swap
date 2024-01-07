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

void	second_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*index;
	int		biggest;
	int		position;
	int		i;

	while ((*stack_b)->next)
	{
		index = *stack_b;
		biggest = index->index;
		position = 0;
		i = 0;
		while (index != NULL)
		{
			if (biggest < index->index)
			{
				biggest = index->index;
				position = i;
			}
			index = index->next;
			i++;
		}
		if (position <= get_length(stack_b) / 2)
		{
			while (position)
			{
				rb(stack_b);
				position--;
			}
			pa(stack_a, stack_b);
		}
		else
		{
			position = get_length(stack_b) - position;
			while (position)
			{
				rrb(stack_b);
				position--;
			}
			pa(stack_a, stack_b);
		}
	}
	pa(stack_a, stack_b);
}

int	find_lower_than(t_stack **stack, int index)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = *stack;
	while (current != NULL)
	{
		if (current->index <= index)
			return (1);
		current = current->next;
	}
	return (0);
}

int	pre_sort(t_stack **stack_a, t_stack **stack_b, int part_len, int ratio)
{
	part_len += ratio;
	while (*stack_a)
	{
		if ((*stack_a)->index <= part_len)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->index > part_len - ratio / 2)
				continue;
			if (*stack_a && (*stack_a)->next && (*stack_a)->index > part_len)
				rr(stack_a, stack_b);
			else
				rb(stack_b);
		}
		else
			ra(stack_a);
		if (!find_lower_than(stack_a, part_len))
			return (part_len);
	}
	return (part_len);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	part_len;
	int	ratio;

	part_len = 0;
	ratio = get_length(stack_a) / 7;
	while (*stack_a)
	{
		part_len = pre_sort(stack_a, stack_b, part_len, ratio);
	}
	second_sort(stack_a, stack_b);
}
