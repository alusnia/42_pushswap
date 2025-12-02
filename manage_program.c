/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:50:52 by alusnia           #+#    #+#             */
/*   Updated: 2025/12/02 06:26:08 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_orders	*set_orders(t_orders *orders)
{
	orders->ra = 0;
	orders->rb = 0;
	orders->rr = 0;
	orders->rra = 0;
	orders->rrb = 0;
	orders->rrr = 0;
	return (orders);
}

t_data	*start_program(int argc, char **argv)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (!data)
		kill_program(data, 1);
	data->argc = argc;
	data->t_info = malloc(sizeof(t_turk_info));
	if (!data->t_info)
		kill_program(data, 1);
	data->t_info->best_node = NULL;
	data->t_info->stack_a_len = argc - 1;
	data->t_info->stack_b_len = 0;
	data->t_info->orders = malloc(sizeof(t_orders));
	data->s_arr = init_s_arr(data, 0);
	if (!data->s_arr || !data->t_info->orders)
		kill_program(data, 1);
	data->t_info->orders = set_orders(data->t_info->orders);
	data->stack_b = NULL;
	data->argv = argv;
	data->i = 0;
	return (data);
}

t_s_int	*init_s_arr(t_data *data, size_t len)
{
	t_s_int	*new;

	if (len == 0)
		new = malloc((data->argc - 1) * sizeof(t_s_int));
	else
		new = malloc((len * sizeof(t_s_int)));
	if (!new)
		kill_program(data, 1);
	return (new);
}

void	kill_program(t_data *data, int error)
{
	if (data && data->t_info && data->t_info->orders)
		free(data->t_info->orders);
	if (data && data->t_info)
		free(data->t_info);
	if (data && data->stack_a)
		stack_clear(&data->stack_a);
	if (data && data->stack_b)
		stack_clear(&data->stack_b);
	if (data && data->s_arr)
		free(data->s_arr);
	if (data && data->argv)
		free_arr(data->argv, data->argc);
	if (data)
		free(data);
	if (error == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}
