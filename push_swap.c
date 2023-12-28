#include "push_swap.h"

static void	print_list(t_stack **stack_1, t_stack **stack_2)
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

static void	algorithm(t_stack **stack_a, t_stack **stack_b)
{

	t_stack	*cursor;
	int		smallest;
	int		position;
	int		i;
	int		total;
	int		moves;

	printf("start\n");
	// print_list(stack_a, stack_b);
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
		// print_list(stack_a, stack_b);
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		moves++;
	}
	// print_list(stack_a, stack_b);
	printf("MOVES:%i", moves);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	check_args(argv);
	make_stack(argv, &stack_a);
	print_list(&stack_a, &stack_b);
	algorithm(&stack_a, &stack_b);	// to be implemented
	terminate(&stack_a, &stack_b, EXIT_SUCCESS);
}
