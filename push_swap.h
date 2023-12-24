#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*make_new_node(int value);
t_stack	*get_last_node(t_stack *first_node);
void	add_node_back(t_stack **first_node, t_stack *new_node);
void	add_node_front(t_stack **first_node, t_stack *new_node);
void	delete_node(t_stack *node);

#endif