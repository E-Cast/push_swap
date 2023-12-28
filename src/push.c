#include "../push_swap.h"

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*new_node;

	if (stack_1 == NULL || *stack_1 == NULL)
		return ;
	new_node = node_unlink(stack_1, *stack_1);
	node_addf(stack_2, new_node);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	printf("pb\n");
}
