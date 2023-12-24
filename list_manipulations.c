#include "push_swap.h"

t_stack	*node_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> value = value;
	node -> next = NULL;
	node -> prev = NULL;
	return (node);
}

