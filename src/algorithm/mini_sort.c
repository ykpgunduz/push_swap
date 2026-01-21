#include "push_swap.h"

static void	move_min_to_top(t_stack_list *stack_a, int min_location)
{
	while (min_location > 0)
	{
		rotate_a(stack_a);
		min_location--;
	}
}

static void	handle_four_elem(t_stack_list *stack_a, t_stack_list *stack_b)
{
	int	min_location;

	min_location = stack_find_pos(stack_a, stack_locate_min(stack_a));
	if (min_location <= 2)
		move_min_to_top(stack_a, min_location);
	else if (min_location == 3)
		rev_rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	sort_triple(stack_a);
	push_to_a(stack_a, stack_b);
}

static void	handle_five_elem(t_stack_list *stack_a, t_stack_list *stack_b)
{
	int	min_location;

	min_location = stack_find_pos(stack_a, stack_locate_min(stack_a));
	if (min_location <= 2)
		move_min_to_top(stack_a, min_location);
	else if (min_location == 3)
	{
		rev_rotate_a(stack_a);
		rev_rotate_a(stack_a);
	}
	else if (min_location == 4)
		rev_rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	handle_four_elem(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}

void	sort_small_set(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (stack_a->size == 2)
		sort_pair(stack_a);
	else if (stack_a->size == 3)
		sort_triple(stack_a);
	else if (stack_a->size == 4)
		handle_four_elem(stack_a, stack_b);
	else if (stack_a->size == 5)
		handle_five_elem(stack_a, stack_b);
}
