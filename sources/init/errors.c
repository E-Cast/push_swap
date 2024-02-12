/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:23 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/12 17:48:22 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Checks if the number string is bigger than MAX_INT or smaller than MIN_INT.*/
void	check_size(char	*str, const char *max)
{
	int	i;

	if (!str || !max)
		terminate(NULL, NULL, EXIT_FAILURE);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 10)
		terminate(NULL, NULL, EXIT_FAILURE);
	if (i < 10)
		return ;
	i = 0;
	while (i < 10)
	{
		if (str[i] > max[i])
			terminate(NULL, NULL, EXIT_FAILURE);
		if (str[i] < max[i])
			return ;
		i++;
	}
}

/*Checks if the character specified inside the string is valid.*/
void	check_char(char *str, size_t i)
{
	if (!str)
		terminate(NULL, NULL, EXIT_FAILURE);
	if (str[i] == '-' && i != 0 && str[i - 1] != ' ')
		terminate(NULL, NULL, EXIT_FAILURE);
	if (str[i] == '-' && !(str[i + 1] >= '1' && str[i + 1] <= '9'))
		terminate(NULL, NULL, EXIT_FAILURE);
	if (str[i] == '0' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (i == 0)
			terminate(NULL, NULL, EXIT_FAILURE);
		if (str[i - 1] == ' ' || str[i - 1] == '-')
			terminate(NULL, NULL, EXIT_FAILURE);
	}
	if (str[i] == ' ' && (i == 0 || str[i + 1] == ' ' || str[i + 1] == '\0'))
		terminate(NULL, NULL, EXIT_FAILURE);
	if (my_isset(str[i], VALID_CHARS) == 1)
		return ;
	terminate(NULL, NULL, EXIT_FAILURE);
}

/*Runs checks on the arguments to ensure they are valid.*/
void	check_args(char **argv)
{
	size_t	i;
	size_t	j;

	if (!argv)
		terminate(NULL, NULL, EXIT_FAILURE);
	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			terminate(NULL, NULL, EXIT_FAILURE);
		j = 0;
		while (argv[i][j])
		{
			check_char(argv[i], j);
			if ((j == 0 || argv[i][j - 1] == ' '))
			{
				if (argv[i][j] == '-')
					check_size(&argv[i][j + 1], MIN_INT);
				else
					check_size(&argv[i][j], MAX_INT);
			}
			j++;
		}
		i++;
	}
}

/*Checks if there is another node with the same value in the stack.*/
void	check_dup(t_stack **stack, t_stack *node)
{
	t_stack	*current_node;

	if (!stack || !node)
		terminate(NULL, NULL, EXIT_FAILURE);
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node != node && current_node->value == node->value)
		{
			free(node);
			terminate(stack, NULL, EXIT_FAILURE);
		}
		current_node = current_node->next;
	}
}
