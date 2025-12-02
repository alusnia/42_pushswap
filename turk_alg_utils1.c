/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:08:47 by alusnia           #+#    #+#             */
/*   Updated: 2025/11/25 11:32:27 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_orders	*get_rr(size_t node, size_t target, t_orders *orders)
{
	orders = set_orders(orders);
	if (node && target && node >= target)
	{
		orders->rr = target;
		orders->rb = node - target;
	}
	else if (node && target && node < target)
	{
		orders->rr = node;
		orders->ra = target - node;
	}
	else
	{
		orders->ra = target;
		orders->rb = node;
	}
	return (orders);
}

t_orders	*get_rrr(size_t node, size_t target, t_orders *orders)
{
	if (node && target && node >= target)
	{
		orders->rrr = target;
		orders->rrb = node - target;
	}
	else if (node && target && node < target)
	{
		orders->rrr = node;
		orders->rra = target - node;
	}
	else
	{
		orders->rra = target;
		orders->rrb = node;
	}
	return (orders);
}

size_t	get_opt_solution(t_turk_node *info, t_orders *orders, char *c)
{
	size_t	i;
	size_t	j;

	*c = 'r';
	i = orders->ra + orders->rb + orders->rr;
	j = orders->rra + orders->rrb + orders->rrr;
	if (j < i)
	{
		i = j;
		*c = 'R';
	}
	j = orders->ra + orders->rrb;
	if (j < i && !info->n_rrotate && !info->target->n_rotate)
	{
		i = j;
		*c = 'a';
	}
	j = orders->rra + orders->rb;
	if (j < i && !info->n_rotate && !info->target->n_rrotate)
	{
		i = j;
		*c = 'b';
	}
	return (i);
}

void	erase_data(size_t *a, size_t *b, size_t *c, size_t *d)
{
	*a = 0;
	*b = 0;
	if (c)
		*c = 0;
	if (d)
		*d = 0;
}

t_orders	*get_new_best_orders(t_orders *orders, char c)
{
	if (c == 'r')
		erase_data(&(orders->rra), &(orders->rrb), &(orders->rrr), NULL);
	else if (c == 'R')
		erase_data(&(orders->ra), &(orders->rb), &(orders->rr), NULL);
	else
	{
		erase_data(&(orders->rr), &(orders->rrr), NULL, NULL);
		if (c == 'a')
			erase_data(&(orders->rb), &(orders->rra), NULL, NULL);
		else if (c == 'b')
			erase_data(&(orders->ra), &(orders->rrb), NULL, NULL);
	}
	return (orders);
}
