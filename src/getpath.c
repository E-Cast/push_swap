#include "../push_swap.h"

static int	get_shortest_path(t_path path)
{
	int	path_1;
	int	path_2;
	int	path_3;
	int	path_4;

	path_1 = path.ra + path.rrb;
	path_2 = path.rra + path.rb;
	path_3 = path.rr + (path.ra - path.rr) + (path.rb - path.rr);
	path_4 = path.rrr + (path.rra - path.rrr) + (path.rrb - path.rrr);
	if (path_1 < path_2 && path_1 < path_3 && path_1 < path_4)
		return (1);
	else if (path_2 < path_1 && path_2 < path_3 && path_2 < path_4)
		return (2);
	else if (path_3 < path_1 && path_3 < path_2 && path_3 < path_4)
		return (3);
	else
		return (4);
}

static int	get_nbr_of_moves(t_path path)
{
	if (path.path == 1)
		return (path.ra + path.rrb);
	else if (path.path == 2)
		return (path.rra + path.rb);
	else if (path.path == 3)
		return (path.rr + (path.ra - path.rr) + (path.rb - path.rr));
	else
		return ((path.rrr + (path.rra - path.rrr) + (path.rrb - path.rrr)));
}

static t_path	get_path(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	t_path	path;
	t_path	new_path;
	int		position;
	int		sorted_pos;

	position = get_position(stack_a, node);
	sorted_pos = get_sorted_position(stack_b, node);
	path.ra = position - 1;
	path.rra = (get_length(stack_a) + 1) - position;
	path.rb = sorted_pos - 1;
	path.rrb = (get_length(stack_b) + 1) - sorted_pos;
	if (path.ra >= path.rb)
		path.rr = path.ra - (path.ra - path.rb);
	else
		path.rr = path.rb - (path.rb - path.ra);
	if (path.rra >= path.rrb)
		path.rrr = path.rra - (path.rra - path.rrb);
	else
		path.rrr = path.rrb - (path.rrb - path.rra);
	path.path = get_shortest_path(path);
	path.moves = get_nbr_of_moves(path);
	path = clean_path(path, new_path);
	return (path);
}

// t_path	clean_path(t_path path, t_path new_path)
// {
// 	t_path	new_path;

// 	new_path.path = path.path;
// 	new_path.moves = path.moves;
// 	if (path.path == 1)
// 	{
// 		new_path.ra = path.ra;
// 		new_path.rrb = path.rrb;
// 	}
// 	else if (path.path == 2)
// 	{
// 		new_path.rra = path.rra;
// 		new_path.rb = path.rb;
// 	}
// 	else if (path.path == 3)
// 	{
// 		new_path.rr = path.rr;
// 		new_path.ra = path.ra - path.rr;
// 		new_path.rb = path.rb - path.rr;
// 	}
// 	else
// 	{
// 		new_path.rrr = path.rrr;
// 		new_path.rra = path.rra - path.rrr;
// 		new_path.rrb = path.rrb - path.rrr;
// 	}
// 	return (new_path);
// }

// void	execute_path(t_path path)
// {
// 	while (path.path == 1)
// 	{

// 	}
// }




// 	}
// 	else if (path.path == 1)
// 	{
		
// 	}
// 	else if (path.path == 1)
// 	{
		
// 	}
// 	else
// 	{

// 	}
// }

// t_path	get_cheapest(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*index;

// 	index = *stack_a;
// 	while (index != NULL)
// 	{

// 	}
// }

