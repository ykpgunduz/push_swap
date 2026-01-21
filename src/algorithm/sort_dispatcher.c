#include "push_swap.h"

void	execute_sort(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (stack_check_order(stack_a))
		return ;
	if (stack_a->size <= 5)
		sort_small_set(stack_a, stack_b);
	else
		sort_bit_manipulation(stack_a, stack_b);
}
