#include "push_swap.h"

// Takes an int as argument and creates a new node with it as value
t_stack	*make_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// Takes a pointer to a node of a list and returns the last node of that list
t_stack	*get_last_node(t_stack *first_node)
{
	t_stack	*current_node;

	if (!first_node)
		return (NULL);
	current_node = first_node;
	while (current_node->next != NULL)
		current_node = current_node->next;
	return (current_node);
}

// Takes a pointer to 
void	add_node_back(t_stack **first_node, t_stack *new_node)
{
	t_stack	*current_node;

	if (!new_node)
		return ;
	if (!*first_node)
		*first_node = new_node;
	else
	{
		current_node = ft_lstlast(*first_node);
		current_node->next = new_node;
		new_node->prev = current_node;
	}
}
