/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   op_swap.c                                             :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:56:11 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:20:48 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_swap(t_stack_list *deque)
{
	t_stack_node	*top;
	t_stack_node	*below;

	if (!deque || !deque->top || !deque->top->next)
		return ;
	top = deque->top;
	below = deque->top->next;
	top->next = below->next;
	below->next = top;
	deque->top = below;
}

void	swap_a(t_stack_list *stack_a)
{
	exec_swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack_list *stack_b)
{
	exec_swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ss(t_stack_list *stack_a, t_stack_list *stack_b)
{
	exec_swap(stack_a);
	exec_swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
