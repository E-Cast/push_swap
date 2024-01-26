#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		blk_len;

	if (argc == 1)
		return (0);
	check_args(argv);
	stack_a = NULL;
	stack_b = NULL;
	make_stack(argv, &stack_a);
	sort_check(&stack_a);
	index_stack(&stack_a);
	if (get_length(&stack_a) <= 3)
		sort_three(&stack_a);
	else if (get_length(&stack_a) <= 15)
		sort_fifteen(); // to do
	else if (get_length(&stack_a) <= 200)
		blk_len = get_length(&stack_a) / BLK_NUM_200;
	else if (get_length(&stack_a) > 200)
		blk_len = get_length(&stack_a) / BLK_NUM_500;
	pre_sort(&stack_a, &stack_b, 0, blk_len); // maybe to optimise
	while (stack_b)
		final_sort(&stack_a, &stack_b, get_length(&stack_b), blk_len / 2); //to finish
	sort_check(&stack_a);
	terminate(&stack_a, NULL, EXIT_FAILURE);
}
