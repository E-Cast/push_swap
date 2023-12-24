#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*node_new(int value);

#endif