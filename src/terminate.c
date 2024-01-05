#include "../push_swap.h"

void	terminate(t_stack **stack_a, t_stack **stack_b, int status)
{
	t_stack	*node;

	while (stack_a != NULL && *stack_a != NULL)
	{
		node = node_unlink(stack_a, *stack_a);
		if (node)
			free(node);
	}
	if (*stack_a)
		free(*stack_a);
	while (stack_b != NULL && *stack_b != NULL)
	{
		node = node_unlink(stack_b, *stack_b);
		if (node)
			free(node);
	}
	if (status == EXIT_FAILURE)
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}
