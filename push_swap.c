#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc == 1)
		return (1);
	tmp_a = args_to_list(argv);
	tmp_b = NULL;
	stack_a = &tmp_a;
	stack_b = &tmp_b;

	printf("start\n");
	print_list(stack_a);

	sa(stack_a);
	print_list(stack_a);

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	print_list(stack_b);
	print_list(stack_a);

	rr(stack_a, stack_b);
	print_list(stack_b);
	print_list(stack_a);

	rrr(stack_a, stack_b);
	print_list(stack_b);
	print_list(stack_a);

	sa(stack_a);
	print_list(stack_b);
	print_list(stack_a);

	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	print_list(stack_a);
}
