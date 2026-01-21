#include "push_swap.h"

static void	exec_rev_rotate(t_stack_list *deque)
{
	t_stack_node	*tail;
	t_stack_node	*before_tail;

	if (!deque || !deque->top || !deque->top->next)
		return ;
	tail = deque->top;
	before_tail = NULL;
	while (tail->next)
	{
		before_tail = tail;
		tail = tail->next;
	}
	before_tail->next = NULL;
	tail->next = deque->top;
	deque->top = tail;
}

void	rev_rotate_a(t_stack_list *stack_a)
{
	exec_rev_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_stack_list *stack_b)
{
	exec_rev_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_rrr(t_stack_list *stack_a, t_stack_list *stack_b)
{
	exec_rev_rotate(stack_a);
	exec_rev_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
