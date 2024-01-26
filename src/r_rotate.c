#include "../push_swap.h"

/*Shift down all elements of stack by 1. The last 
	element becomes the first one.*/
static void	r_rotate(t_stack **stack)
{
	t_stack	*new_node;

	if (stack == NULL || *stack == NULL)
		return ;
	new_node = node_unlink(stack, node_get(stack, -1));
	node_addf(stack, new_node);
}

/*Shift down all elements of stack a by 1. The last 
	element becomes the first one. Print "rra\n" to stdout.*/
void	rra(t_stack **stack_a)
{
	r_rotate(stack_a);
	printf("rra\n");
}

/*Shift down all elements of stack b by 1. The last 
	element becomes the first one. Print "rrb\n" to stdout.*/
void	rrb(t_stack **stack_b)
{
	r_rotate(stack_b);
	printf("rrb\n");
}

/*Execute rra and rrb at the same time. Print "rrr\n" to stdout.*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	printf("rrr\n");
}
