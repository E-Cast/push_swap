/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:20:51 by ecastong          #+#    #+#             */
/*   Updated: 2024/01/26 12:20:52 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Swap the first 2 elements at the top of stack. Do nothing 
	if there is only one or no elements.*/
static void	swap(t_stack **stack)
{
	int		tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

/*Swap the first 2 elements at the top of stack a. Do nothing 
	if there is only one or no elements. Print "sa\n" to stdout.*/
void	sa(t_stack **stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

/*Swap the first 2 elements at the top of stack b. Do nothing 
	if there is only one or no elements. Print "sb\n" to stdout.*/
void	sb(t_stack **stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

/*Execute sa and sb at the same time. Print "ss\n" to stdout.*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}
