#include "../push_swap.h"

/*Free the stacks passed as argument and close the program while returning the 
	exit code, if the exit code indicates failure print "Error\n" on stdout*/
void	terminate(t_stack **stack_a, t_stack **stack_b, int exit_code)
{
	t_stack	*node;

	while (stack_a != NULL && *stack_a != NULL)
	{
		node = node_unlink(stack_a, *stack_a);
		if (node)
			free(node);
	}
	while (stack_b != NULL && *stack_b != NULL)
	{
		node = node_unlink(stack_b, *stack_b);
		if (node)
			free(node);
	}
	if (exit_code == EXIT_FAILURE)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}
