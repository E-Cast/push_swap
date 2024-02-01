/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:20:29 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/01 16:20:29 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Returns the total length of the list received as argument.*/
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

/*Checks if the stack is already sorted, if it is terminate with exit code
	success.*/
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

/*Finds the position of the node in the stack.*/
int	get_position(t_stack **stack, t_stack *node)
{
	t_stack	*current;
	int		position;

	if (!stack || !*stack)
		return (0);
	current = *stack;
	position = 1;
	while (current != NULL)
	{
		if (current == node)
			return (position);
		current = current->next;
		position++;
	}
	return (0);
}

/*Frees the stacks passed as argument and close the program with the appropriate
	exit code. In case of error, it prints "Error\n" on stdout*/
void	terminate(t_stack **stack_a, t_stack **stack_b, int exit_code)
{
	t_stack	*node;

	while (stack_a != NULL && *stack_a != NULL)
	{
		node = node_unlink(stack_a, *stack_a);
		if (node)
			free(node);
	}
	while (stack_b != NULL && *stack_b != NULL)
	{
		node = node_unlink(stack_b, *stack_b);
		if (node)
			free(node);
	}
	if (exit_code == EXIT_FAILURE)
		printf("Error\n");
	exit(exit_code);
}
