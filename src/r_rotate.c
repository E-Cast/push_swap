#include "../push_swap.h"

void	r_rotate(t_stack **stack)
{
	t_stack	*new_node;

	if (stack == NULL || *stack == NULL)
		return ;
	new_node = node_create(node_last(stack)->value);
	node_addf(stack, new_node);
	node_delete(stack, node_last(stack));
}

void	rra(t_stack **stack_a)
{
	r_rotate(stack_a);
	printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	r_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	printf("rrr\n");
}
