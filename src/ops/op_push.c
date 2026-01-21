/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   op_push.c                                             :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:56:54 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:21:05 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	exec_push(t_stack_list *target, t_stack_list *source)
{
	t_stack_node	*elem;

	if (!source || !source->top)
		return ;
	elem = source->top;
	source->top = source->top->next;
	source->size--;
	elem->next = target->top;
	target->top = elem;
	target->size++;
}

void	push_to_a(t_stack_list *stack_a, t_stack_list *stack_b)
{
	exec_push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	push_to_b(t_stack_list *stack_a, t_stack_list *stack_b)
{
	exec_push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}
