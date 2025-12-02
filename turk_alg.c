/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:35:45 by alusnia           #+#    #+#             */
/*   Updated: 2025/11/26 06:54:02 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_turk_node	*get_total_cost(t_list **node, t_turk_info ***t_info)
{
	t_turk_node	*target;
	t_orders	*orders;
	size_t		cost;
	char		c;

	orders = malloc(sizeof(t_orders));
	if (!orders)
		return (NULL);
	target = (*node)->info->target;
	orders = get_rr((*node)->info->n_rotate, target->n_rotate, orders);
	orders = get_rrr((*node)->info->n_rrotate, target->n_rrotate, orders);
	cost = get_opt_solution((*node)->info, orders, &c);
	if (!(**t_info)->best_node || cost < (**t_info)->best_node->total_cost)
	{
		free((**t_info)->orders);
		(**t_info)->best_node = (*node)->info;
		(**t_info)->best_node->total_cost = cost;
		(**t_info)->orders = get_new_best_orders(orders, c);
	}
	else
		free(orders);
	(*node)->info->total_cost = cost;
	return ((*node)->info);
}

static t_turk_node	*set_target(t_list *node,
		t_list *stack_a, t_turk_info **t_info)
{
	size_t	value;
	t_list	*target;
	t_list	*temp;

	target = NULL;
	temp = stack_a;
	value = node->index;
	while (temp)
	{
		if (temp->index > value && (!target || target->index > temp->index))
			target = temp;
		if (target && target->index == value + 1)
			break ;
		temp = temp->next;
	}
	if (!target)
		target = smallest(stack_a);
	node->info->target = target->info;
	node->info = get_total_cost(&node, &t_info);
	return (node->info);
}

t_turk_node	*calc_cost(t_turk_node *info, size_t len, size_t i)
{
	if (i != 0 && ((i < len / 2) || ((i <= len / 2) && len % 2 == 1)))
	{
		info->to_top_cost = i;
		info->n_rotate = len - i;
		info->n_rrotate = i;
	}
	else if (i != 0 && i == len / 2)
	{
		info->to_top_cost = i;
		info->n_rrotate = i;
		info->n_rotate = i;
	}
	else if (i == 0)
		erase_data(&info->n_rotate, &info->n_rrotate,
			&info->to_top_cost, &info->total_cost);
	else
	{
		info->to_top_cost = len - i + ((len + 1) % 2);
		info->n_rrotate = i;
		info->n_rotate = len - i;
	}
	return (info);
}

static t_data	*collect_info(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list		*temp;
	t_turk_info	*t_info;
	size_t		i;

	t_info = data->t_info;
	i = 0;
	temp = *stack_a;
	while (temp)
	{
		temp->info = calc_cost(temp->info, t_info->stack_a_len, i++);
		temp = temp->next;
	}
	temp = *stack_b;
	i = 0;
	while (temp)
	{
		temp->info = calc_cost(temp->info, t_info->stack_b_len, i++);
		temp->info = set_target(temp, *stack_a, &t_info);
		if (!temp->info)
			kill_program(data, 1);
		temp = temp->next;
	}
	data->t_info = t_info;
	return (data);
}

t_data	*turk_sort(t_data *data,
		t_list *stack_a, t_list *stack_b, t_turk_info *t_info)
{
	if (is_sorted(stack_a))
		return (data);
	while (t_info->stack_a_len > 3 && !is_sorted(stack_a))
		push(&stack_a, &stack_b, &t_info, 'b');
	stack_a = easy_sort(stack_a, t_info->stack_a_len);
	while (t_info->stack_b_len)
	{
		data = collect_info(data, &stack_a, &stack_b);
		data = execute_order(data, stack_a, stack_b);
		stack_a = data->stack_a;
		stack_b = data->stack_b;
		t_info = data->t_info;
		push(&stack_b, &stack_a, &t_info, 'a');
	}
	if (!is_sorted(stack_a))
		data = low_to_top(data, stack_a, data->t_info->stack_a_len);
	else
		data->stack_a = stack_a;
	return (data);
}
