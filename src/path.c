#include "../push_swap.h"

t_path	zero_path(t_path path)
{
	path.ra = 0;
	path.rra = 0;
	path.rb = 0;
	path.rrb = 0;
	path.rr = 0;
	path.rrr = 0;
	return (path);
}

t_path	clean_path(int shortest, t_path old_path, t_path path)
{
	if (shortest == 1)
	{
		path.ra = old_path.ra;
		path.rrb = old_path.rrb;
	}
	else if (shortest == 2)
	{
		path.rra = old_path.rra;
		path.rb = old_path.rb;
	}
	else if (shortest == 3)
	{
		path.rr = old_path.rr;
		path.ra = old_path.ra - old_path.rr;
		path.rb = old_path.rb - old_path.rr;
	}
	else
	{
		path.rrr = old_path.rrr;
		path.rra = old_path.rra - old_path.rrr;
		path.rrb = old_path.rrb - old_path.rrr;
	}
	path.moves = path.ra + path.rra + path.rb + path.rrb + path.rr + path.rrr;
	return (path);
}

static t_path	get_shortest_path(t_path path)
{
	int		path_1;
	int		path_2;
	int		path_3;
	int		path_4;
	int		shortest;

	path_1 = path.ra + path.rrb;
	path_2 = path.rra + path.rb;
	path_3 = path.rr + (path.ra - path.rr) + (path.rb - path.rr);
	path_4 = path.rrr + (path.rra - path.rrr) + (path.rrb - path.rrr);
	if (path_1 < path_2 && path_1 < path_3 && path_1 < path_4)
		shortest = 1;
	else if (path_2 < path_1 && path_2 < path_3 && path_2 < path_4)
		shortest = 2;
	else if (path_3 < path_1 && path_3 < path_2 && path_3 < path_4)
		shortest = 3;
	else
		shortest = 4;
	path = clean_path(shortest, path, zero_path(path));
	return (path);
}

t_path	get_path(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	t_path	path;
	int		position;
	int		sorted_pos;

	position = get_position(stack_b, node);
	sorted_pos = get_sorted_position(stack_a, node->value);
	path.ra = sorted_pos - 1;
	path.rra = (get_length(stack_a) + 1) - sorted_pos;
	path.rb = position - 1;
	path.rrb = (get_length(stack_b) + 1) - position;
	if (path.ra >= path.rb)
		path.rr = path.ra - (path.ra - path.rb);
	else
		path.rr = path.rb - (path.rb - path.ra);
	if (path.rra >= path.rrb)
		path.rrr = path.rra - (path.rra - path.rrb);
	else
		path.rrr = path.rrb - (path.rrb - path.rra);
	path = get_shortest_path(path);
	return (path);
}

void	execute_path(t_stack **stack_a, t_stack **stack_b, t_path path)
{
	ra(stack_a, path.ra);
	rra(stack_a, path.rra);
	rb(stack_b, path.rb);
	rrb(stack_b, path.rrb);
	rr(stack_a, stack_b, path.rr);
	rrr(stack_a, stack_b, path.rrr);
}
