#include "../push_swap.h"

void	terminate(t_stack **stack_1, t_stack **stack_2, int status)
{
	t_stack	*node;

	while (stack_1 != NULL && *stack_1 != NULL)
	{
		node = node_unlink(stack_1, *stack_1);
		if (node)
			free(node);
	}
	while (stack_2 != NULL && *stack_2 != NULL)
	{
		node = node_unlink(stack_2, *stack_2);
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
