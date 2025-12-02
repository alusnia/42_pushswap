/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 06:52:54 by alusnia           #+#    #+#             */
/*   Updated: 2025/11/27 09:27:17 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	val_arg(t_data *data, char *arg)
{
	long	i;

	i = 0;
	while (arg[i] && (ft_isdigit((int)arg[i]) || (arg[i] == '-' && i == 0)))
		i++;
	if (arg[i])
		kill_program(data, 1);
	i = ft_atol(arg);
	if (i > INT_MAX || i < INT_MIN)
		kill_program(data, 1);
	return ((int)i);
}

static void	export_input(t_data *data, int argc, char **argv)
{
	int		i;
	int		n;
	t_list	*temp;

	i = 1;
	while (i < argc)
	{
		n = val_arg(data, argv[i]);
		temp = NULL;
		temp = make_stack(n);
		if (temp && i == 1)
			data->stack_a = temp;
		else if (!stack_add_back(&data->stack_a, temp))
			kill_program(data, 1);
		data->s_arr[i - 1].val = n;
		data->s_arr[i - 1].ptr = temp;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_data	*temp;

	if (argc == 2)
	{
		argv = export_argv(argv[1], &argc);
		data = start_program(argc, argv);
		if (!argv)
			kill_program(data, 1);
	}
	else
		data = start_program(argc, NULL);
	if (argc == 1)
		kill_program(data, 1);
	export_input(data, argc, argv);
	temp = quick_sort_alg(data, data->s_arr, data->argc - 1);
	if (!temp)
		kill_program(data, 1);
	data = temp;
	data = index_arr(data);
	data = turk_sort(data, data->stack_a, data->stack_b, data->t_info);
	data->stack_b = NULL;
	kill_program(data, 0);
}
