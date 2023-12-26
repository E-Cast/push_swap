#include "push_swap.h"

void	super_algorithm_x3000(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cursor;
	int		smallest;
	int		position;
	int		i;
	int		total;
	int		moves;

	printf("start\n");
	print_list(stack_a, stack_b);
	moves = 0;
	while (*stack_a)
	{
		cursor = *stack_a;
		total = 0;
		while (cursor)
		{
			cursor = cursor->next;
			total++;
		}
		cursor = *stack_a;
		smallest = cursor->value;
		position = 0;
		i = 0;
		while (cursor)
		{
			if (smallest > cursor->value)
			{
				smallest = cursor->value;
				position = i;
			}
			cursor = cursor->next;
			i++;
		}
		if (total - position > position)
		{
			while (position > 0)
			{
				ra(stack_a);
				moves++;
				position--;
			}
		}
		else
		{
			while (position < total)
			{
				rra(stack_a);
				moves++;
				position++;
			}
		}
		pb(stack_a, stack_b);
		moves++;
		print_list(stack_a, stack_b);
	}
	while (*stack_b)
	{
		pa(stack_b, stack_a);
		moves++;
	}
	print_list(stack_a, stack_b);
	printf("MOVES:%i", moves);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = args_to_list(argv, NULL);
	stack_b = NULL;
	super_algorithm_x3000(&stack_a, &stack_b);
}
