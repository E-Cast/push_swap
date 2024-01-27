#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

// Constants' definitions.

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

# ifndef BLK_NUM_200
#  define BLK_NUM_200 4
# endif

# ifndef BLK_NUM_500
#  define BLK_NUM_500 7
# endif

// Node manipulation functions.

t_stack	*node_create(int value, t_stack **stack);
t_stack	*node_get(t_stack **stack, int position);
void	node_addb(t_stack **stack, t_stack *new_node);
void	node_addf(t_stack **stack, t_stack *new_node);
t_stack	*node_unlink(t_stack **stack, t_stack *node);

// Sorting operations.

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// Error handling.

void	terminate(t_stack **stack_a, t_stack **stack_b, int exit_code);
void	check_args(char **argv);
void	check_dup(t_stack **stack, t_stack *node);

// Stack creation.

void	make_stack(char **argv, t_stack **stack);
void	index_stack(t_stack **stack);

// Utility.

int		get_length(t_stack **stack);
void	sort_check(t_stack **stack);
int		get_position(t_stack **stack, t_stack *node);

// Sorting algorithms.

void	sort_three(t_stack **stack);
void	pre_sort(t_stack **stack_a, t_stack **stack_b, int total, int blk_len);
void	final_sort(t_stack **stack_a, t_stack **stack_b, int todo, int blk_len);

int		get_cheapest(t_stack **stack_a, t_stack **stack_b);

#endif