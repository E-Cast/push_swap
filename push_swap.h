#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

# define VALID_CHARS " 1234567890"
# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

// list manipulation functions
t_stack	*node_create(int value, t_stack **stack);
t_stack	*node_last(t_stack **first_node);
void	node_addb(t_stack **first_node, t_stack *new_node);
void	node_addf(t_stack **first_node, t_stack *new_node);
t_stack	*node_unlink(t_stack **first_node, t_stack *node);

// parsing functions
void	is_char_valid(char *chr, t_stack **stack);
void	size_check(char	*str, const char *max, t_stack **stack);
t_stack	*args_to_list(char **argv, t_stack *stack);
int		str_to_int(const char *str);

// utility functions
void	print_list(t_stack **stack_1, t_stack **stack_2);
void	terminate(t_stack **stack_1, t_stack **stack_2);

// sorting operation functions
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_1, t_stack **stack_2);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	r_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif