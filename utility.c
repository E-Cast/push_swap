#include "push_swap.h"

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
