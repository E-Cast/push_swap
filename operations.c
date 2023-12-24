#include "push_swap.h"

void	swap(t_stack **stack)
{
	int		tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;

	return ;
}

void	swap2(t_stack **stack_1, t_stack **stack_2)
{
	swap(stack_1);
	swap(stack_2);

	return ;
}

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*new_node;

	if (*stack_1 == NULL)
		return ;
	new_node = node_create((*stack_1)->value);
	node_addf(stack_2, new_node);
	node_delete(stack_1, *stack_1);

	return ;
}

void	rotate(t_stack **stack)
{
	t_stack	*new_node;

	if (stack == NULL)
		return ;
	new_node = node_create((*stack)->value);
	node_addb(stack, new_node);
	node_delete(stack, *stack);

	return ;
}

void	rotate2(t_stack **stack_1, t_stack **stack_2)
{
	rotate(stack_1);
	rotate(stack_2);
}

void	r_rotate(t_stack **stack)
{
	t_stack	*new_node;

	if (stack == NULL)
		return ;
	new_node = node_create(node_last(stack)->value);
	node_addf(stack, new_node);
	node_delete(stack, node_last(stack));

	return ;
}

void	r_rotate2(t_stack **stack_1, t_stack **stack_2)
{
	r_rotate(stack_1);
	r_rotate(stack_2);
}
