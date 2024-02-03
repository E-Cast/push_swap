/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:20:54 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/03 13:08:15 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*Converts a string into an integer.*/
int	ps_atoi(char *str, t_stack **stack)
{
	size_t	i;
	int		sign;
	int		num;

	if (!str)
		terminate(stack, NULL, EXIT_FAILURE);
	i = 0;
	sign = 1;
	num = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - 48) * sign;
		i++;
	}
	return (num);
}

/*Creates new nodes from argv and puts them at the end of stack.*/
void	make_stack(char **argv, t_stack **stack)
{
	t_stack	*node;
	size_t	i;
	size_t	j;

	if (!argv || !stack)
		terminate(stack, NULL, EXIT_FAILURE);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 || argv[i][j - 1] == ' ')
			{
				node = node_create(ps_atoi(&argv[i][j], stack), stack);
				check_dup(stack, node);
				node_addb(stack, node);
			}
			j++;
		}
		i++;
	}
}
