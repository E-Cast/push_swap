/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:02:05 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/04 20:55:56 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*Checks if the stack is already sorted, if it is terminate with exit code
	success.*/
int	sort_check(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*last_node;

	if (!stack_a || !*stack_a)
		return (0);
	current = (*stack_a)->next;
	last_node = *stack_a;
	while (current)
	{
		if (last_node && last_node->value > current->value)
			return (1);
		last_node = current;
		current = current->next;
	}
	terminate(stack_a, stack_b, EXIT_SUCCESS);
	return (0);
}

/*Ensures the input string is valid and executes it.
	If it isn't, prints "Error\n" to stderr.*/
void	check_input(t_stack **stack_a, t_stack **stack_b, char *input)
{
	if (ft_strncmp(input, "pa\n", 100) == 0)
		pa(stack_a, stack_b, 1);
	else if (ft_strncmp(input, "pb\n", 100) == 0)
		pb(stack_a, stack_b, 1);
	else if (ft_strncmp(input, "rra\n", 100) == 0)
		rra(stack_a, 1);
	else if (ft_strncmp(input, "rrb\n", 100) == 0)
		rrb(stack_b, 1);
	else if (ft_strncmp(input, "rrr\n", 100) == 0)
		rrr(stack_a, stack_b, 1);
	else if (ft_strncmp(input, "ra\n", 100) == 0)
		ra(stack_a, 1);
	else if (ft_strncmp(input, "rb\n", 100) == 0)
		rb(stack_b, 1);
	else if (ft_strncmp(input, "rr\n", 100) == 0)
		rr(stack_a, stack_b, 1);
	else if (ft_strncmp(input, "sa\n", 100) == 0)
		sa(stack_a);
	else if (ft_strncmp(input, "sb\n", 100) == 0)
		sb(stack_b);
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*input;

	if (argc == 1)
		return (0);
	check_args(argv);
	stack_a = NULL;
	stack_b = NULL;
	(void) stack_b;
	(void) argv;
	make_stack(argv, &stack_a);
	input = get_next_line(STDIN_FILENO);
	while (input != NULL)
	{
		check_input(&stack_a, &stack_b, input);
		my_safefree(input);
		input = get_next_line(STDIN_FILENO);
	}
	my_safefree(input);
	if (sort_check(&stack_a, &stack_b) == 0 && stack_b == NULL)
		terminate(&stack_a, &stack_b, EXIT_SUCCESS);
	terminate(&stack_a, &stack_b, 2);
}
