/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:20:51 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/04 18:03:45 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*Swaps the first 2 elements at the top of stack. Does nothing 
	if there is only one or no elements.*/
void	swap(t_stack **stack)
{
	int		tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

/*Swaps the first 2 elements at the top of stack_a. Does nothing 
	if there is only one or no elements. Prints "sa\n" to stdout.*/
void	sa(t_stack **stack_a)
{
	swap(stack_a);
}

/*Swaps the first 2 elements at the top of stack_b. Does nothing 
	if there is only one or no elements. Prints "sb\n" to stdout.*/
void	sb(t_stack **stack_b)
{
	swap(stack_b);
}

/*Executes sa and sb at the same time. Prints "ss\n" to stdout.*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
