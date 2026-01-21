/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   radix_sort.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:54:39 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:21:37 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_bit_depth(int total)
{
	int	depth;

	depth = 0;
	while ((total - 1) >> depth)
		depth++;
	return (depth);
}

static void	process_bit_level(t_stack_list *stack_a,
		t_stack_list *stack_b, int bit_pos)
{
	int	total;
	int	iter;

	total = stack_a->size;
	iter = 0;
	while (iter < total)
	{
		if (((stack_a->top->index >> bit_pos) & 1) == 0)
			push_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		iter++;
	}
}

void	sort_bit_manipulation(t_stack_list *stack_a, t_stack_list *stack_b)
{
	int	bit_depth;
	int	bit_pos;

	node_set_index(stack_a);
	bit_depth = calculate_bit_depth(stack_a->size);
	bit_pos = 0;
	while (bit_pos < bit_depth)
	{
		process_bit_level(stack_a, stack_b, bit_pos);
		while (stack_b->size > 0)
			push_to_a(stack_a, stack_b);
		bit_pos++;
	}
}
