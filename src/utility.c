/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:20:29 by ecastong          #+#    #+#             */
/*   Updated: 2024/01/26 13:09:38 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Return the total length of the list received as argument.*/
int	get_length(t_stack **stack)
{
	t_stack	*cursor;
	int		i;

	if (!stack || !*stack)
		return (0);
	cursor = *stack;
	i = 0;
	while (cursor)
	{
		cursor = cursor->next;
		i++;
	}
	return (i);
}

/*Check if the stack received as argument is already sorted, if it is 
	terminate with exit code success. A stack with only 1 element is 
	always considered sorted.*/
void	sort_check(t_stack **stack)
{
	t_stack	*current;
	t_stack	*last_node;

	if (!stack || !*stack)
		return ;
	current = (*stack)->next;
	last_node = *stack;
	while (current)
	{
		if (last_node && last_node->value > current->value)
			return ;
		last_node = current;
		current = current->next;
	}
	terminate(stack, NULL, EXIT_SUCCESS);
}

/*Find the position of the node in the stack.*/
int	get_position(t_stack **stack, t_stack *node)
{
	t_stack	*current;
	int		position;

	current = *stack;
	position = 1;
	while (current && current != node)
	{
		current = current->next;
		position++;
	}
	return (position);
}
