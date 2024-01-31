/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:20:57 by ecastong          #+#    #+#             */
/*   Updated: 2024/01/31 15:32:56 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Sort three or less elements under three moves.*/
void	sort_three(t_stack **stack)
{
	if (get_length(stack) > 2)
	{
		if (find_biggest(stack)->index == node_get(stack, 1)->index)
			ra(stack, 1);
		else if (find_biggest(stack)->index == node_get(stack, 2)->index)
			rra(stack, 1);
	}
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
	sort_check(stack);
}
