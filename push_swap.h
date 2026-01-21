#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int						value;
	int						index;
	int						pos;
	int						dest_pos;
	int						move_cost_a;
	int						move_cost_b;
	struct s_stack_node		*next;
}	t_stack_node;

typedef struct s_stack_list
{
	t_stack_node	*top;
	int				size;
}	t_stack_list;

t_stack_list	*stack_init(void);
void			stack_free(t_stack_list *stack);
int				stack_check_order(t_stack_list *stack);
void			node_insert_back(t_stack_list *stack, int value);
void			node_set_index(t_stack_list *stack);
int				stack_locate_min(t_stack_list *stack);
int				stack_find_pos(t_stack_list *stack, int value);
void			push_to_a(t_stack_list *stack_a, t_stack_list *stack_b);
void			push_to_b(t_stack_list *stack_a, t_stack_list *stack_b);
void			swap_a(t_stack_list *stack_a);
void			swap_b(t_stack_list *stack_b);
void			swap_ss(t_stack_list *stack_a, t_stack_list *stack_b);
void			rotate_a(t_stack_list *stack_a);
void			rotate_b(t_stack_list *stack_b);
void			rotate_rr(t_stack_list *stack_a, t_stack_list *stack_b);
void			rev_rotate_a(t_stack_list *stack_a);
void			rev_rotate_b(t_stack_list *stack_b);
void			rev_rotate_rrr(t_stack_list *stack_a, t_stack_list *stack_b);
void			execute_sort(t_stack_list *stack_a, t_stack_list *stack_b);
void			sort_pair(t_stack_list *stack_a);
void			sort_triple(t_stack_list *stack_a);
void			sort_small_set(t_stack_list *stack_a, t_stack_list *stack_b);
void			sort_bit_manipulation(t_stack_list *stack_a,
					t_stack_list *stack_b);
int				process_input(int argc, char **argv, t_stack_list *stack_a);
int				verify_num_format(char *str);
int				detect_duplicates(t_stack_list *stack);
void			free_str_array(char **arr);
void			terminate_with_error(void);
void			cleanup_resources(t_stack_list *stack_a, t_stack_list *stack_b);

#endif
