#include "push_swap.h"

static int	locate_max_position(t_stack_list *deque)
{
	t_stack_node	*curr;
	int				max_val;
	int				max_loc;
	int				loc;

	curr = deque->top;
	max_val = curr->value;
	max_loc = 0;
	loc = 0;
	while (curr)
	{
		if (curr->value > max_val)
		{
			max_val = curr->value;
			max_loc = loc;
		}
		curr = curr->next;
		loc++;
	}
	return (max_loc);
}

void	sort_triple(t_stack_list *stack_a)
{
	int	max_loc;

	if (stack_check_order(stack_a))
		return ;
	max_loc = locate_max_position(stack_a);
	if (max_loc == 0)
		rotate_a(stack_a);
	else if (max_loc == 1)
		rev_rotate_a(stack_a);
	if (stack_a->top->value > stack_a->top->next->value)
		swap_a(stack_a);
}

void	sort_pair(t_stack_list *stack_a)
{
	if (stack_a->top->value > stack_a->top->next->value)
		swap_a(stack_a);
}
