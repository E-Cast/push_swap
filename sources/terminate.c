/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:47:26 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/04 20:44:25 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Frees the stacks passed as argument and close the program with the appropriate
	exit code. In case of error, it prints "Error\n" on stderr*/
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
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(exit_code);
}
