/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecast <ecast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:20:54 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/10 19:11:28 by ecast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
				node = node_create(ft_atoi(&argv[i][j]), stack);
				check_dup(stack, node);
				node_addb(stack, node);
			}
			j++;
		}
		i++;
	}
}
