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
		biggest = index->value;
		position = 0;
		i = 0;
		while (index != NULL)
		{
			if (biggest < index->value)
			{
				biggest = index->value;
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

int	lower_than(t_stack **stack, int value)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = *stack;
	while (current != NULL)
	{
		if (current->value <= value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	pre_sort(t_stack **stack_a, t_stack **stack_b, int blk_len, int ratio)
{
	t_stack *marker;

	marker = NULL;
	blk_len += ratio;
	while (*stack_a && *stack_a != marker)
	{
		if ((*stack_a)->value <= blk_len)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->value <= blk_len - ratio / 2)
			{
				if (*stack_a && (*stack_a)->next && (*stack_a)->value > blk_len)
					rr(stack_a, stack_b);
				else
					rb(stack_b);
			}
		}
		else
			ra(stack_a);
		if (lower_than(stack_a, blk_len))
				return (blk_len);
	}
	return (blk_len);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	blk_len;
	int	ratio;

	blk_len = 0;
	ratio = get_length(stack_a) / 7;
	while (*stack_a)
	{
		blk_len = pre_sort(stack_a, stack_b, blk_len, ratio);
	}
	second_sort(stack_a, stack_b);
}
