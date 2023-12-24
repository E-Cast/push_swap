#include "push_swap.h"

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

void	add_node_front(t_stack **first_node, t_stack *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *first_node;
	(*first_node)->prev = new_node;
	*first_node = new_node;
}

void	delete_node(t_stack *node)
{
	t_stack	*prev_node;
	t_stack	*next_node;

	if (node == NULL)
		return ;
	prev_node = node->prev;
	next_node = node->next;
	prev_node->next = next_node;
	next_node->prev = prev_node;
	free(node);
}
	