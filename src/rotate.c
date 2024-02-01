/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:00 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/01 15:53:45 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../push_swap.h"

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
	element becomes the last one. Prints "ra\n" to stdout.*/
void	ra(t_stack **stack_a, int iterations)
{
	while (iterations--)
	{
		rotate(stack_a);
		printf("ra\n");
	}
}

/*Shifts up all elements of stac_ b by 1. The first 
	element becomes the last one. Prints "rb\n" to stdout.*/
void	rb(t_stack **stack_b, int iterations)
{
	while (iterations > 0)
	{
		rotate(stack_b);
		printf("rb\n");
		iterations--;
	}
}

/*Executes ra and rb at the same time. Prints "rr\n" to stdout.*/
void	rr(t_stack **stack_a, t_stack **stack_b, int iterations)
{
	while (iterations--)
	{
		rotate(stack_a);
		rotate(stack_b);
		printf("rr\n");
	}
}
