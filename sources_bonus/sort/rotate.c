/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:00 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/04 20:43:30 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*Shifts up all elements of stack by 1. The first 
	element becomes the last one.*/
void	rotate(t_stack **stack)
{
	t_stack	*new_node;

	if (stack == NULL || *stack == NULL)
		return ;
	new_node = node_unlink(stack, *stack);
	node_addb(stack, new_node);
}

/*Shifts up all elements of stack_a by 1. The first 
	element becomes the last one.*/
void	ra(t_stack **stack_a, int iterations)
{
	while (iterations--)
		rotate(stack_a);
}

/*Shifts up all elements of stac_ b by 1. The first 
	element becomes the last one.*/
void	rb(t_stack **stack_b, int iterations)
{
	while (iterations--)
		rotate(stack_b);
}

/*Executes ra and rb at the same time.*/
void	rr(t_stack **stack_a, t_stack **stack_b, int iterations)
{
	while (iterations--)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}
