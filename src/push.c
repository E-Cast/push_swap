/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:06 by ecastong          #+#    #+#             */
/*   Updated: 2024/01/28 14:40:32 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Take the first element at the top of stack_1 and put it at the top of stack_2.
	Do nothing if stack_1 is empty.*/
static void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*new_node;

	if (stack_1 == NULL || *stack_1 == NULL)
		return ;
	new_node = node_unlink(stack_1, *stack_1);
	node_addf(stack_2, new_node);
}

/*Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty. Print "pa\n" to stdout.*/
void	pa(t_stack **stack_a, t_stack **stack_b, int iterations)
{
	while (iterations)
	{
		push(stack_b, stack_a);
		printf("pa\n");
		iterations--;
	}
}

/*Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty. Print "pb\n" to stdout.*/
void	pb(t_stack **stack_a, t_stack **stack_b, int iterations)
{
	while (iterations)
	{
		push(stack_a, stack_b);
		printf("pb\n");
		iterations--;
	}
}
