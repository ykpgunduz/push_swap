/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   op_rotate.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:56:05 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:20:50 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	exec_rotate(t_stack_list *deque)
{
	t_stack_node	*top;
	t_stack_node	*tail;

	if (!deque || !deque->top || !deque->top->next)
		return ;
	top = deque->top;
	tail = deque->top;
	while (tail->next)
		tail = tail->next;
	deque->top = top->next;
	top->next = NULL;
	tail->next = top;
}

void	rotate_a(t_stack_list *stack_a)
{
	exec_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack_list *stack_b)
{
	exec_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_rr(t_stack_list *stack_a, t_stack_list *stack_b)
{
	exec_rotate(stack_a);
	exec_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
