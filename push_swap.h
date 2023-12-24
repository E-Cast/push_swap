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

t_stack	*node_create(int value);
t_stack	*node_last(t_stack *first_node);
void	node_addb(t_stack **first_node, t_stack *new_node);
void	node_addf(t_stack **first_node, t_stack *new_node);
void	node_delete(t_stack **first_node, t_stack *node);

t_stack	*args_to_list(char **argv);
int		ft_atoi(const char *str);
void	print_list(t_stack **first_node);

void	swap(t_stack **stack);
void	swap2(t_stack **stack_a, t_stack **stack_b);

#endif