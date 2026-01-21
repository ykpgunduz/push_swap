#include "push_swap.h"

void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	terminate_with_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	cleanup_resources(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (stack_a)
		stack_free(stack_a);
	if (stack_b)
		stack_free(stack_b);
	terminate_with_error();
}
