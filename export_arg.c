/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 06:41:04 by alusnia           #+#    #+#             */
/*   Updated: 2025/11/25 11:08:02 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_arr(char **ptr, int argc)
{
	size_t	i;

	i = 0;
	while (i < (size_t)argc)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

static char	**sep_arr(char *s, size_t *k)
{
	char	**ptr;
	char	*start;
	size_t	i;
	size_t	j;

	ptr = NULL;
	i = 1;
	j = ft_strlen(s);
	if (j == 0)
	{
		ptr = malloc(sizeof(char *));
		return (ptr);
	}
	start = s;
	while (j > 1)
	{
		if (start[--j] == ' ' && (j == 0 || start[j - 1] != ' '))
			i++;
		if (start[j] == ' ')
			start[j] = '\0';
	}
	ptr = malloc((i + 1) * sizeof(char *));
	*k = i + 1;
	return (ptr);
}

char	**export_argv(char *start, int *argc)
{
	char	**ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(start) + 1;
	ptr = NULL;
	ptr = sep_arr(start, &i);
	*argc = i;
	if (i != 0 && ptr)
	{
		while (i > 1 && --j >= 0)
		{
			if (start[j] != 0 && (j == 0 || start[j - 1] == 0))
			{
				ptr[i - 1] = ft_calloc(ft_strlen(start + j) + 1, sizeof(char));
				if (!ptr[i - 1])
					return (free_arr(ptr, *argc));
				ft_strlcpy(ptr[i-- - 1], start + j, ft_strlen(start + j) + 1);
			}
		}
	}
	ptr[0] = NULL;
	return (ptr);
}
