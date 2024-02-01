/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:10 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/01 14:54:44 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../push_swap.h"

/*Creates a new node with the value received as argument.*/
t_stack	*node_create(int value, t_stack **stack)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		terminate(stack, NULL, EXIT_FAILURE);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*Gets the node at the specified position in the stack.
	If the position is -1, get the last node of the stack.*/
t_stack	*node_get(t_stack **stack, int position)
{
	t_stack	*current_node;

	if (!stack)
		return (NULL);
	current_node = *stack;
	while (position < 0 && current_node->next != NULL)
		current_node = current_node->next;
	while (position > 1 && current_node->next != NULL)
	{
		current_node = current_node->next;
		position--;
	}
	return (current_node);
}

/*Adds the node to the end of the stack.*/
void	node_addb(t_stack **stack, t_stack *new_node)
{
	t_stack	*current_node;

	if (!new_node)
		terminate(NULL, NULL, EXIT_FAILURE);
	if (!*stack)
		*stack = new_node;
	else
	{
		current_node = node_get(stack, -1);
		current_node->next = new_node;
		new_node->prev = current_node;
	}
}

/*Adds the node to the front of the stack.*/
void	node_addf(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		terminate(NULL, NULL, EXIT_FAILURE);
	if (!*stack)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/*Unlinks the node from it's stack and return it.*/
t_stack	*node_unlink(t_stack **stack, t_stack *node)
{
	t_stack	*prev_node;
	t_stack	*next_node;

	if (!node || !stack)
		terminate(NULL, NULL, EXIT_FAILURE);
	prev_node = node->prev;
	next_node = node->next;
	node->prev = NULL;
	node->next = NULL;
	if (prev_node)
		prev_node->next = next_node;
	if (next_node)
		next_node->prev = prev_node;
	if (*stack == node)
		*stack = next_node;
	return (node);
}
