/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   stack_manager.c                                       :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:56:46 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:21:11 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack_list	*stack_init(void)
{
	t_stack_list	*deque;

	deque = (t_stack_list *)ft_calloc(1, sizeof(t_stack_list));
	if (!deque)
		return (NULL);
	return (deque);
}

void	stack_free(t_stack_list *deque)
{
	t_stack_node	*curr;
	t_stack_node	*nxt;

	if (!deque)
		return ;
	curr = deque->top;
	while (curr)
	{
		nxt = curr->next;
		free(curr);
		curr = nxt;
	}
	free(deque);
}

int	stack_check_order(t_stack_list *deque)
{
	t_stack_node	*curr;

	if (!deque || !deque->top)
		return (1);
	curr = deque->top;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}
