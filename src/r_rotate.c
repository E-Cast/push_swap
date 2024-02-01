/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:43:44 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/01 16:15:47 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Shifts down all elements of stack by 1. The last 
	element becomes the first one.*/
void	r_rotate(t_stack **stack)
{
	t_stack	*new_node;

	if (stack == NULL || *stack == NULL)
		return ;
	new_node = node_unlink(stack, node_get(stack, -1));
	node_addf(stack, new_node);
}

/*Shifts down all elements of stack_a by 1. The last 
	element becomes the first one. Prints "rra\n" to stdout.*/
void	rra(t_stack **stack_a, int iterations)
{
	while (iterations--)
	{
		r_rotate(stack_a);
		printf("rra\n");
	}
}

/*Shifts down all elements of stack_b by 1. The last 
	element becomes the first one. Prints "rrb\n" to stdout.*/
void	rrb(t_stack **stack_b, int iterations)
{
	while (iterations--)
	{
		r_rotate(stack_b);
		printf("rrb\n");
	}
}

/*Executes rra and rrb at the same time. Prints "rrr\n" to stdout.*/
void	rrr(t_stack **stack_a, t_stack **stack_b, int iterations)
{
	while (iterations--)
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
		printf("rrr\n");
	}
}
