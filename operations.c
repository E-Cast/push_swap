#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int		tmp;

	if (*stack_a == NULL && (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;

	return ;
}

void	sb(t_stack **stack_b)
{
	int		tmp;

	if (*stack_b == NULL && (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tmp;

	return ;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);

	return ;
}

void	pa(t_stack **stack_a);
void	pb(t_stack **stack_b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
