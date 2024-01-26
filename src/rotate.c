/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:00 by ecastong          #+#    #+#             */
/*   Updated: 2024/01/26 12:21:02 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Shift up all elements of stack by 1. The first 
	element becomes the last one.*/
static void	rotate(t_stack **stack)
{
	t_stack	*new_node;

	if (stack == NULL || *stack == NULL)
		return ;
	new_node = node_unlink(stack, *stack);
	node_addb(stack, new_node);
}

/*Shift up all elements of stack a by 1. The first 
	element becomes the last one. Print "ra\n" to stdout.*/
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

/*Shift up all elements of stack b by 1. The first 
	element becomes the last one. Print "rb\n" to stdout.*/
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

/*Execute ra and rb at the same time. Print "rr\n" to stdout.*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}
