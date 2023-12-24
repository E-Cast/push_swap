#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*new_node;

	if (stack == NULL)
		return ;
	new_node = node_create((*stack)->value);
	node_addb(stack, new_node);
	node_delete(stack, *stack);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}
