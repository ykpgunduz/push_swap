/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   input_validator.c                                     :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:56:31 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:20:37 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	verify_num_format(char *str)
{
	int	idx;

	idx = 0;
	if (!str || !str[0])
		return (0);
	if (str[idx] == '+' || str[idx] == '-')
		idx++;
	if (!str[idx])
		return (0);
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

int	detect_duplicates(t_stack_list *deque)
{
	t_stack_node	*elem;
	t_stack_node	*scan;

	elem = deque->top;
	while (elem)
	{
		scan = elem->next;
		while (scan)
		{
			if (elem->value == scan->value)
				return (1);
			scan = scan->next;
		}
		elem = elem->next;
	}
	return (0);
}
