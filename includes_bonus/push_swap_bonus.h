#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/*Structs.*/

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*Constants.*/

# define VALID_CHARS " -0123456789"
# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

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



char	*get_next_line(int fd);

#endif