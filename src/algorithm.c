#include "../push_swap.h"

// void	print_list(t_stack **stack_1, t_stack **stack_2)
// {
// 	t_stack	*cursor_1;
// 	t_stack	*cursor_2;

// 	cursor_1 = *stack_1;
// 	cursor_2 = *stack_2;
// 	printf("---------\na	b\n\n");
// 	while (cursor_1 && cursor_2)
// 	{
// 		printf("%i	%i\n", cursor_1->value, cursor_2->value);
// 		cursor_1 = cursor_1->next;
// 		cursor_2 = cursor_2->next;
// 	}
// 	while (cursor_1)
// 	{
// 		printf("%i\n", cursor_1->value);
// 		cursor_1 = cursor_1->next;
// 	}
// 	while (cursor_2)
// 	{
// 		printf("	%i\n", cursor_2->value);
// 		cursor_2 = cursor_2->next;
// 	}
// 	printf("---------\n");
// 	return ;
// }

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
// 		biggest = index->value;
// 		position = 0;
// 		i = 0;
// 		while (index != NULL)
// 		{
// 			if (biggest < index->value)
// 			{
// 				biggest = index->value;
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
// 		// print_list(stack_a, stack_b);
// 	}
// 	pa(stack_a, stack_b);
// }

// int	get_average_value(t_stack **stack)
// {
// 	int		num;
// 	int		i;
// 	t_stack	*index;

// 	if (!stack && !*stack)
// 		return (0);
// 	num = 0;
// 	i = 0;
// 	index = *stack;
// 	while (index != NULL)
// 	{
// 		num += index->value;
// 		index = index->next;
// 		i++;
// 	}
// 	return (num / i);
// }

// void	quick_sort(t_stack **stack_a, t_stack **stack_b, int average)
// {
// 	t_stack	*marker;
// 	int		ratio;

// 	marker = NULL;
// 	ratio = 0;
// 	while (*stack_a && (*stack_a)->next->next && *stack_a != marker)
// 	{
// 		if ((*stack_a)->value < average)
// 		{
// 			pb(stack_a, stack_b);
// 			ratio++;
// 		}
// 		else
// 		{
// 			if (marker == NULL)
// 				marker = *stack_a;
// 			if (ratio >= 2)
// 			{
// 				rr(stack_a, stack_b);
// 				ratio -= 2;
// 			}
// 			else
// 				ra(stack_a);
// 		}
// 	}
// }

// void	algorithm(t_stack **stack_a, t_stack **stack_b)
// {
// 	if (get_length(stack_a) == 2)
// 	{
// 		if ((*stack_a)->value > (*stack_a)->next->value)
// 			sa(stack_a);
// 		return ;
// 	}
// 	while (*stack_a && (*stack_a)->next->next)
// 	{
// 		quick_sort(stack_a, stack_b, get_average_value(stack_a));
// 	}
// 	if ((*stack_a)->next && (*stack_a)->next->value < (*stack_a)->value)
// 		sa(stack_a);
// 	second_sort(stack_a, stack_b);
// }

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int		fraction;
	int		blk_len;
	t_stack *marker;

	fraction = get_length(stack_a) / 4;
	blk_len = 0;
	printf("%i\n", fraction);
	marker = NULL;
	while (*stack_a)
	{
		blk_len += fraction;
		// printf("%i\n", blk_len);
		while (*stack_a && *stack_a != marker)
		{
			if ((*stack_a)->value <= blk_len)
			{
				if ((*stack_a)->value <= blk_len - fraction / 2)
				{
					pb(stack_a, stack_b);
					rb(stack_b);
				}
				else
					pb(stack_a, stack_b);
			}
			else
			{
				if (marker == NULL)
					marker = *stack_a;
				ra(stack_a);
			}
		}
		marker = NULL;
	}
}
