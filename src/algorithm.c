#include "../push_swap.h"

void	print_list(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*cursor_1;
	t_stack	*cursor_2;

	cursor_1 = *stack_1;
	cursor_2 = *stack_2;
	printf("---------\na	b\n\n");
	while (cursor_1 && cursor_2)
	{
		printf("%i	%i\n", cursor_1->value, cursor_2->value);
		cursor_1 = cursor_1->next;
		cursor_2 = cursor_2->next;
	}
	while (cursor_1)
	{
		printf("%i\n", cursor_1->value);
		cursor_1 = cursor_1->next;
	}
	while (cursor_2)
	{
		printf("	%i\n", cursor_2->value);
		cursor_2 = cursor_2->next;
	}
	printf("---------\n");
	return ;
}

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

int	get_average_value(t_stack **stack)
{
	int		num;
	int		i;
	t_stack	*index;

	if (!stack && !*stack)
		return (0);
	num = 0;
	i = 0;
	index = *stack;
	while (index != NULL)
	{
		num += index->value;
		index = index->next;
		i++;
	}
	return (num / i);
}


void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*marker;
	int		average_value;

	while (*stack_a && (*stack_a)->next->next)
	{
		marker = NULL;
		average_value = get_average_value(stack_a);
		while (*stack_a && (*stack_a)->next->next && *stack_a != marker)
		{
			if ((*stack_a)->value < average_value)
				pb(stack_a, stack_b);
			else
			{
				if (marker == NULL)
					marker = *stack_a;
				ra(stack_a);
			}
		}
		marker = NULL;
	}
	if ((*stack_a)->next && (*stack_a)->next->value < (*stack_a)->value)
		sa(stack_a);
	// print_list(stack_a, stack_b);
}
