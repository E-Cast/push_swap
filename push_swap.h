#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

# define VALID_CHARS " -1234567890"
# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

// node manipulation functions
t_stack	*node_create(int value, t_stack **stack);
t_stack	*node_get(t_stack **first_node, int position);
void	node_addb(t_stack **first_node, t_stack *new_node);
void	node_addf(t_stack **first_node, t_stack *new_node);
t_stack	*node_unlink(t_stack **first_node, t_stack *node);

// error handling functions
void	check_size(char	*str, const char *max);
void	check_char(char *str, size_t i);
void	check_args(char **argv);
void	check_dup(t_stack **first_node, t_stack *node);
void	terminate(t_stack **stack_a, t_stack **stack_b, int status);

// list creation functions
int		ft_atoi(char *str);
void	make_stack(char **argv, t_stack **stack);

// algoritm functions
int		get_length(t_stack **stack);
void	algorithm(t_stack **stack_a, t_stack **stack_b);
void	pre_sort(t_stack **stack_a, t_stack **stack_b, int total, int blk_len);

// sorting operation functions
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_1, t_stack **stack_2);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	r_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	print_list(t_stack **stack_1, t_stack **stack_2); // testing function

#endif