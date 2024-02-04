/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:02:05 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/04 18:02:07 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	printf("OK\n");
	terminate(stack, NULL, EXIT_SUCCESS);
}

void	check_input(t_stack **stack_a, t_stack **stack_b, char *input)
{
	if (ft_strncmp(input, "pa\n", 100) == 0)
		pa(stack_a, stack_b, 1);
	if (ft_strncmp(input, "pb\n", 100) == 0)
		pb(stack_a, stack_b, 1);
	if (ft_strncmp(input, "rra\n", 100) == 0)
		rra(stack_a, 1);
	if (ft_strncmp(input, "rrb\n", 100) == 0)
		rrb(stack_b, 1);
	if (ft_strncmp(input, "rrr\n", 100) == 0)
		rrr(stack_a, stack_b, 1);
	if (ft_strncmp(input, "ra\n", 100) == 0)
		ra(stack_a, 1);
	if (ft_strncmp(input, "rb\n", 100) == 0)
		rb(stack_b, 1);
	if (ft_strncmp(input, "rr\n", 100) == 0)
		rr(stack_a, stack_b, 1);
	if (ft_strncmp(input, "sa\n", 100) == 0)
		sa(stack_a);
	if (ft_strncmp(input, "sb\n", 100) == 0)
		sb(stack_b);
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
		input = get_next_line(STDIN_FILENO);
	}
	sort_check(&stack_a);
	printf("KO\n");
	terminate(&stack_a, &stack_a, 2);
}
