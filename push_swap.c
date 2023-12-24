#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = args_to_list(argv);
	stack_b = NULL;

	printf("start\n");
	print_list(&stack_a);
	printf("sa\n");
	swap(&stack_a);
	print_list(&stack_a);
	printf("pb pb pb\n");
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	print_list(&stack_b);
	print_list(&stack_a);
	printf("rr\n");
	rotate2(&stack_a, &stack_b);
	print_list(&stack_b);
	print_list(&stack_a);
	printf("rrr\n");
	r_rotate2(&stack_a, &stack_b);
	print_list(&stack_b);
	print_list(&stack_a);
	printf("sa\n");
	swap(&stack_a);
	print_list(&stack_b);
	print_list(&stack_a);
	printf("pa pa pa\n");
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	print_list(&stack_a);
}
