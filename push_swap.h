/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 06:53:07 by alusnia           #+#    #+#             */
/*   Updated: 2025/11/14 06:53:07 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf.h"

//structs-----------------------------------------------------------------------

typedef struct s_s_int
{
	int				val;
	struct s_list	*ptr;
}	t_s_int;

typedef struct s_turk_node
{
	size_t				to_top_cost;
	size_t				total_cost;
	size_t				n_rotate;
	size_t				n_rrotate;
	struct s_turk_node	*target;
}	t_turk_node;

typedef struct s_orders
{
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}	t_orders;

typedef struct s_turk_info
{
	size_t		stack_a_len;
	size_t		stack_b_len;
	t_orders	*orders;
	t_turk_node	*best_node;

}	t_turk_info;

typedef struct s_sort_i
{
	size_t	left_i;
	size_t	left_t_i;
	size_t	right_i;
	size_t	right_t_i;
	size_t	len;
	size_t	pivot;
	int		value;
}	t_sort_i;

typedef struct s_list
{
	int				content;
	size_t			index;
	t_turk_node		*info;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_s_int		*s_arr;
	t_turk_info	*t_info;
	int			argc;
	char		**argv;
	size_t		i;
}	t_data;

//export_arg--------------------------------------------------------------------
char		**free_arr(char **ptr, int argc);
char		**export_argv(char *start, int *argc);
//lst_manage--------------------------------------------------------------------
t_list		*make_stack(int content);
void		stack_clear(t_list **lst);
int			stack_add_back(t_list **lst, t_list *new);
//quicksort.c-------------------------------------------------------------------
t_data		*quick_sort_alg(t_data *data, t_s_int *s_arr, size_t i);
t_data		*index_arr(t_data *data);
//manage_program.c--------------------------------------------------------------
t_orders	*set_orders(t_orders *orders);
t_data		*start_program(int argc, char **argv);
t_s_int		*init_s_arr(t_data *data, size_t len);
void		clear_s_arr(t_s_int *s_arr);
void		kill_program(t_data *data, int error);
//turk_alg.c--------------------------------------------------------------------
t_turk_node	*calc_cost(t_turk_node *info, size_t len, size_t i);
t_data		*turk_sort(t_data *data, t_list *stack_a,
				t_list *stack_b, t_turk_info *t_info);
t_list		*easy_sort(t_list *stack_a, size_t argc);
//turk_alg_utils1.c-------------------------------------------------------------
t_orders	*get_rr(size_t node, size_t target, t_orders *orders);
t_orders	*get_rrr(size_t node, size_t target, t_orders *orders);
size_t		get_opt_solution(t_turk_node *info, t_orders *orders, char *c);
t_orders	*get_new_best_orders(t_orders *orders, char c);
void		erase_data(size_t *a, size_t *b, size_t *c, size_t *d);
//turk_alg_utils2.c-------------------------------------------------------------
t_list		*smallest(t_list *stack_a);
t_data		*low_to_top(t_data *data, t_list *stack_a, size_t len);
int			is_sorted(t_list *stack);
t_data		*execute_order(t_data *data, t_list *stack_a, t_list *stack_b);
//push_swap_utils.c-------------------------------------------------------------
void		swap(t_list **stack, char c);
void		sswap(t_list **stack_a, t_list **stack_b);
void		push(t_list **from, t_list **to, t_turk_info **t_info, char c);
//push_swap_utils2.c------------------------------------------------------------
void		rotate(t_list **stack, char c);
void		srotate(t_list **stack_a, t_list **stack_b);
void		rrotate(t_list **stack, char c);
void		srrotate(t_list **stack_a, t_list **stack_b);

#endif