/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:20:54 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/01 00:26:16 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Converts a string into an integer.*/
static int	ft_atoi(char *str)
{
	size_t	i;
	int		sign;
	int		num;

	if (!str)
		return (0);
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

/*Create new nodes from argv and put them at the end of stack.*/
void	make_stack(char **argv, t_stack **stack)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 || argv[i][j - 1] == ' ')
			{
				node_addb(stack, node_create(ft_atoi(&argv[i][j]), stack));
				check_dup(stack, node_get(stack, -1));
			}
			j++;
		}
		i++;
	}
}
