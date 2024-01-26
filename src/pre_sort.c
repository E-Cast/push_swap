/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:21:08 by ecastong          #+#    #+#             */
/*   Updated: 2024/01/26 12:21:09 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Find the smallest element above a certain value.*/
static int	find_smaller_than(t_stack **stack, int index)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = *stack;
	while (current != NULL)
	{
		if (current->index <= index)
			return (1);
		current = current->next;
	}
	return (0);
}

/*Transfer stack_a into stack_b, seperated into a predetermined 
	number of pre sorted blocks. The smallest ones in the middle 
	and the biggest at the start and end of stack_b*/
void	pre_sort(t_stack **stack_a, t_stack **stack_b, int total, int blk_len)
{
	total += blk_len;
	while (*stack_a)
	{
		if ((*stack_a)->index <= total)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->index > total - blk_len / 2)
				continue ;
			if (*stack_a && (*stack_a)->next && (*stack_a)->index > total)
				rr(stack_a, stack_b);
			else
				rb(stack_b);
		}
		else
			ra(stack_a);
		if (!find_smaller_than(stack_a, total))
			break ;
	}
	if (*stack_a)
		return (pre_sort(stack_a, stack_b, total, blk_len));
}
