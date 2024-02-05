/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:06 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/04 20:42:52 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*Takes the first element at the top of stack_1 and puts it at the top of
	stack_2. Does nothing if stack_1 is empty.*/
void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*new_node;

	if (stack_1 == NULL || stack_2 == NULL || *stack_1 == NULL)
		return ;
	new_node = node_unlink(stack_1, *stack_1);
	node_addf(stack_2, new_node);
}

/*Takes the first element at the top of stack_b and puts it at the top of
	stack_a. Does nothing if stack_b is empty.*/
void	pa(t_stack **stack_a, t_stack **stack_b, int iterations)
{
	while (iterations--)
		push(stack_b, stack_a);
}

/*Takes the first element at the top of stack_a and puts it at the top of
	stack_b. Does nothing if stack_a is empty.*/
void	pb(t_stack **stack_a, t_stack **stack_b, int iterations)
{
	while (iterations--)
		push(stack_a, stack_b);
}
