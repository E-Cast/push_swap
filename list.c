#include "push_swap.h"

t_stack	*node_create(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*node_last(t_stack **first_node)
{
	t_stack	*current_node;

	if (!first_node)
		return (NULL);
	current_node = *first_node;
	while (current_node->next != NULL)
		current_node = current_node->next;
	return (current_node);
}

void	node_addb(t_stack **first_node, t_stack *new_node)
{
	t_stack	*current_node;

	if (!new_node)
		return ;
	if (!*first_node)
		*first_node = new_node;
	else
	{
		current_node = node_last(first_node);
		current_node->next = new_node;
		new_node->prev = current_node;
	}
}

void	node_addf(t_stack **first_node, t_stack *new_node)
{
	if (!new_node)
		return ;
	if (!*first_node)
		*first_node = new_node;
	else
	{
		new_node->next = *first_node;
		(*first_node)->prev = new_node;
		*first_node = new_node;
	}
}

t_stack	*node_unlink(t_stack **first_node, t_stack *node)
{
	t_stack	*prev_node;
	t_stack	*next_node;

	if (node == NULL)
		return (NULL);
	prev_node = node->prev;
	next_node = node->next;
	node->prev = NULL;
	node->next = NULL;
	if (prev_node)
		prev_node->next = next_node;
	if (next_node)
		next_node->prev = prev_node;
	if (*first_node == node)
		*first_node = next_node;
	return (node);
}

void	node_delete(t_stack **first_node, t_stack *node)
{
	node = node_unlink(first_node, node);
	if (node)
		free(node);
}
