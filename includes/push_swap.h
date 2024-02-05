/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:24:54 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/04 19:57:18 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

/*Structs.*/

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct path
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
	int		moves;
}	t_path;

/*Constants.*/

# define VALID_CHARS " -0123456789"
# define MAX_INT "2147483647"
# define MIN_INT "2147483648"

/*Utility.*/

void	terminate(t_stack **stack_a, t_stack **stack_b, int exit_code);

/*Stack creation.*/

void	check_size(char	*str, const char *max);
void	check_char(char *str, size_t i);
void	check_args(char **argv);
void	check_dup(t_stack **stack, t_stack *node);
t_stack	*node_create(int value, t_stack **stack);
t_stack	*node_get(t_stack **stack, int position);
void	node_addb(t_stack **stack, t_stack *new_node);
void	node_addf(t_stack **stack, t_stack *new_node);
t_stack	*node_unlink(t_stack **stack, t_stack *node);
int		ps_atoi(char *str, t_stack **stack);
void	make_stack(char **argv, t_stack **stack);

/*Sorting operations.*/

void	push(t_stack **stack_1, t_stack **stack_2);
void	pa(t_stack **stack_a, t_stack **stack_b, int iterations);
void	pb(t_stack **stack_a, t_stack **stack_b, int iterations);
void	r_rotate(t_stack **stack);
void	rra(t_stack **stack_a, int iterations);
void	rrb(t_stack **stack_b, int iterations);
void	rrr(t_stack **stack_a, t_stack **stack_b, int iterations);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a, int iterations);
void	rb(t_stack **stack_b, int iterations);
void	rr(t_stack **stack_a, t_stack **stack_b, int iterations);
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/*Sorting functions.*/

int		get_length(t_stack **stack);
void	sort_check(t_stack **stack);
int		get_position(t_stack **stack, t_stack *node);
t_path	zero_path(t_path path);
t_path	clean_path(int shortest, t_path old_path, t_path path);
t_path	get_shortest_path(t_path path);
t_path	get_path(t_stack **stack_a, t_stack **stack_b, t_stack *node);
void	execute_path(t_stack **stack_a, t_stack **stack_b, t_path path);
void	sort_three(t_stack **stack);
t_stack	*get_biggest(t_stack **stack);
int		get_sorted_position(t_stack **stack, int index);
t_path	get_cheapest(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);

#endif