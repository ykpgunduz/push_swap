#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_list	*stack_a;
	t_stack_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = stack_init();
	stack_b = stack_init();
	if (!stack_a || !stack_b)
	{
		if (stack_a)
			stack_free(stack_a);
		if (stack_b)
			stack_free(stack_b);
		terminate_with_error();
	}
	if (!process_input(argc, argv, stack_a))
	{
		stack_free(stack_a);
		stack_free(stack_b);
		terminate_with_error();
	}
	execute_sort(stack_a, stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
