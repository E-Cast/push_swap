#include "../push_swap.h"

t_stack	*node_create(int value, t_stack **stack)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		terminate(stack, NULL, EXIT_FAILURE);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*node_get(t_stack **first_node, int position)
{
	t_stack	*current_node;

	if (!first_node)
		return (NULL);
	current_node = *first_node;
	while (position < 0 && current_node->next != NULL)
		current_node = current_node->next;
	while (position > 1 && current_node->next != NULL)
	{
		current_node = current_node->next;
		position--;
	}
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
		current_node = node_get(first_node, -1);
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
