/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:20:57 by ecastong          #+#    #+#             */
/*   Updated: 2024/01/29 14:39:12 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Sort three or less elements under three moves.*/
void	sort_three(t_stack **stack)
{
	if (get_length(stack) > 2)
	{
		if (node_get(stack, 1)->index == 3)
			ra(stack, 1);
		else if (node_get(stack, 2)->index == 3)
			rra(stack, 1);
	}
	if ((*stack)->index != 1)
		sa(stack);
	sort_check(stack);
}
