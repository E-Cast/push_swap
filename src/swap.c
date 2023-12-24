#include "../push_swap.h"

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

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}
