/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   stack_analyzer.c                                      :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:56:40 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:21:14 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_locate_min(t_stack_list *deque)
{
	t_stack_node	*curr;
	int				min_val;

	if (!deque || !deque->top)
		return (0);
	curr = deque->top;
	min_val = curr->value;
	while (curr)
	{
		if (curr->value < min_val)
			min_val = curr->value;
		curr = curr->next;
	}
	return (min_val);
}

int	stack_locate_max(t_stack_list *deque)
{
	t_stack_node	*curr;
	int				max_val;

	if (!deque || !deque->top)
		return (0);
	curr = deque->top;
	max_val = curr->value;
	while (curr)
	{
		if (curr->value > max_val)
			max_val = curr->value;
		curr = curr->next;
	}
	return (max_val);
}

int	stack_find_pos(t_stack_list *deque, int data)
{
	t_stack_node	*curr;
	int				position;

	curr = deque->top;
	position = 0;
	while (curr)
	{
		if (curr->value == data)
			return (position);
		curr = curr->next;
		position++;
	}
	return (-1);
}

void	stack_bring_to_top(t_stack_list *deque, int position, char deque_id)
{
	int	total;

	total = deque->size;
	if (position <= total / 2)
	{
		while (position > 0)
		{
			if (deque_id == 'a')
				rotate_a(deque);
			else
				rotate_b(deque);
			position--;
		}
	}
	else
	{
		while (position < total)
		{
			if (deque_id == 'a')
				rev_rotate_a(deque);
			else
				rev_rotate_b(deque);
			position++;
		}
	}
}
