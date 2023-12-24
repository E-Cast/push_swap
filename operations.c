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
	node_addb(stack_2, new_node);
	node_delete(stack_1, *stack_1);

	return ;
}

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
