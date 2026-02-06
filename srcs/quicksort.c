/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:59:03 by alusnia           #+#    #+#             */
/*   Updated: 2026/02/06 17:37:04 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_s_int	*sort_to_temp(t_s_int *s_arr,
		t_s_int *temp, t_sort_i *i, size_t *pivot)
{
	while (i->right_i - i->left_i != 0)
	{
		if (s_arr[i->left_i].val < i->value)
			temp[i->left_t_i++] = s_arr[i->left_i++];
		else if (s_arr[i->left_i].val > i->value)
			temp[i->right_t_i--] = s_arr[i->left_i++];
		else if (i->left_i != i->pivot)
			return (NULL);
		if (i->right_i - i->left_i == 0)
			break ;
		if (s_arr[i->right_i].val < i->value)
			temp[i->left_t_i++] = s_arr[i->right_i--];
		else if (s_arr[i->right_i].val > i->value)
			temp[i->right_t_i--] = s_arr[i->right_i--];
		else if (i->right_i != i->pivot)
			return (NULL);
	}
	*pivot = i->left_t_i;
	temp[i->left_t_i] = s_arr[i->left_i];
	return (temp);
}

static t_data	*divide(t_data *data,
		t_s_int *s_arr, t_s_int *temp, size_t *len)
{
	t_sort_i	i;
	size_t		pivot;

	i.left_i = 0;
	i.left_t_i = 0;
	i.right_i = *len - 1;
	i.right_t_i = *len - 1;
	i.len = *len;
	i.pivot = (*len / 2) - ((*len + 1) % 2);
	i.value = s_arr[i.pivot].val;
	temp = sort_to_temp(s_arr, temp, &i, &pivot);
	if (!temp)
		return (NULL);
	if (pivot > 0)
		data = quick_sort_alg(data, temp, pivot);
	if (data)
		data = quick_sort_alg(data, &(temp[pivot]), 1);
	if (data && pivot < *len - 1)
		data = quick_sort_alg(data, &(temp[pivot + 1]), *len - pivot - 1);
	return (data);
}

t_data	*index_arr(t_data *data)
{
	data->i = 0;
	while (data->i++ < (size_t)data->argc - 1)
		data->s_arr[data->i - 1].ptr->index = data->i - 1;
	free(data->s_arr);
	data->s_arr = NULL;
	return (data);
}

static t_data	*switch_val(t_data *data, t_s_int *s_arr, t_s_int *temp)
{
	temp = malloc (sizeof(t_s_int));
	if (!temp)
		kill_program(data, 1);
	if (s_arr[0].val > s_arr[1].val)
	{
		*temp = s_arr[0];
		data->s_arr[data->i++] = s_arr[1];
		data->s_arr[data->i++] = temp[0];
	}
	else if (s_arr[0].val < s_arr[1].val)
	{
		data->s_arr[data->i++] = s_arr[0];
		data->s_arr[data->i++] = s_arr[1];
	}
	else
		return (free(temp), NULL);
	free(temp);
	return (data);
}

t_data	*quick_sort_alg(t_data *data, t_s_int *s_arr, size_t i)
{
	t_s_int	*temp;

	temp = NULL;
	if (i > 2)
	{
		temp = init_s_arr(data, i);
		data = divide(data, s_arr, temp, &i);
		if (!temp)
			kill_program (data, 1);
	}
	else if (i == 2)
		data = switch_val(data, s_arr, temp);
	else if (i == 1)
		data->s_arr[data->i++] = s_arr[0];
	free(temp);
	return (data);
}
