/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   sort_dispatcher.c                                     :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:54:52 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:21:40 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_sort(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (stack_check_order(stack_a))
		return ;
	if (stack_a->size <= 5)
		sort_small_set(stack_a, stack_b);
	else
		sort_bit_manipulation(stack_a, stack_b);
}
