#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

// Constants' definitions.

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

# define VALID_CHARS " -0123456789"
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
void	pa(t_stack **stack_a, t_stack **stack_b, int iterations);
void	pb(t_stack **stack_a, t_stack **stack_b, int iterations);
void	ra(t_stack **stack_a, int iterations);
void	rb(t_stack **stack_b, int iterations);
void	rr(t_stack **stack_a, t_stack **stack_b, int iterations);
void	rra(t_stack **stack_a, int iterations);
void	rrb(t_stack **stack_b, int iterations);
void	rrr(t_stack **stack_a, t_stack **stack_b, int iterations);

// Error handling.

void	terminate(t_stack **stack_a, t_stack **stack_b, int exit_code);

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

t_stack	*find_biggest(t_stack **stack);
int		get_sorted_position(t_stack **stack, int index);
t_path	get_path(t_stack **stack_a, t_stack **stack_b, t_stack *node);
void	execute_path(t_stack **stack_a, t_stack **stack_b, t_path path);
void	sort(t_stack **stack_a, t_stack **stack_b);

int		ps_atoi(char *str, t_stack **stack);

void	push(t_stack **stack_1, t_stack **stack_2);
void	r_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	swap(t_stack **stack);

/*Error handling.*/

void	check_size(char	*str, const char *max);
void	check_char(char *str, size_t i);
void	check_args(char **argv);
void	check_dup(t_stack **stack, t_stack *node);

#endif