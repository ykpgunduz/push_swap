/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   node_manager.c                                        :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:56:06 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:21:17 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_insert_back(t_stack_list *deque, int data)
{
	t_stack_node	*elem;
	t_stack_node	*current;

	elem = (t_stack_node *)ft_calloc(1, sizeof(t_stack_node));
	if (!elem)
		return ;
	elem->value = data;
	elem->index = -1;
	if (!deque->top)
		deque->top = elem;
	else
	{
		current = deque->top;
		while (current->next)
			current = current->next;
		current->next = elem;
	}
	deque->size++;
}

int	node_extract_front(t_stack_list *deque)
{
	t_stack_node	*temp;
	int				val;

	if (!deque || !deque->top)
		return (0);
	temp = deque->top;
	val = temp->value;
	deque->top = deque->top->next;
	free(temp);
	deque->size--;
	return (val);
}

void	node_set_index(t_stack_list *deque)
{
	t_stack_node	*curr;
	t_stack_node	*iter;
	int				rnk;

	curr = deque->top;
	while (curr)
	{
		rnk = 0;
		iter = deque->top;
		while (iter)
		{
			if (curr->value > iter->value)
				rnk++;
			iter = iter->next;
		}
		curr->index = rnk;
		curr = curr->next;
	}
}

void	node_update_pos(t_stack_list *deque)
{
	t_stack_node	*curr;
	int				position;

	curr = deque->top;
	position = 0;
	while (curr)
	{
		curr->pos = position;
		curr = curr->next;
		position++;
	}
}
