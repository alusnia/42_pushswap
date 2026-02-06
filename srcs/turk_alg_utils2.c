/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:38:51 by alusnia           #+#    #+#             */
/*   Updated: 2025/11/25 11:46:28 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*smallest(t_list *stack_a)
{
	t_list	*node;

	node = stack_a;
	while (stack_a)
	{
		if (stack_a->index < node->index)
			node = stack_a;
		stack_a = stack_a->next;
	}
	return (node);
}

t_data	*low_to_top(t_data *data, t_list *stack_a, size_t len)
{
	t_list	*temp;
	size_t	i;

	i = 0;
	temp = stack_a;
	while (temp->index != 0)
	{
		temp = temp->next;
		i++;
	}
	temp->info = calc_cost(temp->info, len, i);
	if (temp->info->n_rotate < temp->info->n_rrotate)
		data->t_info->orders->ra = temp->info->n_rotate;
	else
		data->t_info->orders->rra = temp->info->n_rrotate;
	data = execute_order(data, stack_a, data->stack_b);
	return (data);
}

t_list	*easy_sort(t_list *stack, size_t len)
{
	size_t	val[3];

	if (len == 1)
		return (stack);
	val[0] = stack->index;
	val[1] = stack->next->index;
	if (len == 3)
		val[2] = stack->next->next->index;
	if (len == 2 && val[0] > val[1])
		return (swap(&stack, 'a'), stack);
	else if (val[0] < val[2] && val[2] < val[1])
		return (rotate(&stack, 'a'), swap(&stack, 'a'), stack);
	else if (val[1] < val[0] && val[0] < val[2])
		return (swap(&stack, 'a'), stack);
	else if (val[2] < val[0] && val[0] < val[1])
		return (rotate(&stack, 'a'), stack);
	else if (val[2] < val[1] && val[1] < val[0])
		return (swap(&stack, 'a'), rotate(&stack, 'a'), stack);
	else if (val[1] < val[2] && val[2] < val[0])
		return (rrotate(&stack, 'a'), stack);
	return (stack);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->index + 1 == stack->next->index)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

t_data	*execute_order(t_data *data, t_list *stack_a, t_list *stack_b)
{
	t_orders	*orders;

	orders = data->t_info->orders;
	while (orders->ra--)
		rotate(&stack_a, 'a');
	while (orders->rb--)
		rotate(&stack_b, 'b');
	while (orders->rr--)
		srotate(&stack_a, &stack_b);
	while (orders->rra--)
		rrotate(&stack_a, 'a');
	while (orders->rrb--)
		rrotate(&stack_b, 'b');
	while (orders->rrr--)
		srrotate(&stack_a, &stack_b);
	data->t_info->orders = set_orders(orders);
	data->t_info->best_node = NULL;
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	return (data);
}
