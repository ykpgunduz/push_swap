/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   arg_parser.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/02 22:56:18 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/21 17:20:45 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_single_arg(char *input, t_stack_list *stack_a)
{
	long	val;

	if (!verify_num_format(input))
		return (0);
	val = ft_atoi(input);
	if (val > INT_MAX || val < INT_MIN)
		return (0);
	node_insert_back(stack_a, (int)val);
	return (1);
}

static int	handle_arg_array(char **inputs, t_stack_list *stack_a)
{
	int	idx;

	idx = 0;
	while (inputs[idx])
	{
		if (!handle_single_arg(inputs[idx], stack_a))
			return (0);
		idx++;
	}
	return (1);
}

static int	process_string_arg(char *str, t_stack_list *stack_a)
{
	char	**split_input;
	int		result;

	split_input = ft_split(str, ' ');
	if (!split_input || !split_input[0])
	{
		if (split_input)
			free_str_array(split_input);
		return (0);
	}
	result = handle_arg_array(split_input, stack_a);
	free_str_array(split_input);
	return (result);
}

static int	process_multi_args(int argc, char **argv, t_stack_list *stack_a)
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		if (!handle_single_arg(argv[idx], stack_a))
			return (0);
		idx++;
	}
	return (1);
}

int	process_input(int argc, char **argv, t_stack_list *stack_a)
{
	int	success;

	if (argc == 2)
		success = process_string_arg(argv[1], stack_a);
	else
		success = process_multi_args(argc, argv, stack_a);
	if (!success || detect_duplicates(stack_a))
		return (0);
	return (1);
}
