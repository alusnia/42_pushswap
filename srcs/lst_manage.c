/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:48:44 by alusnia           #+#    #+#             */
/*   Updated: 2025/11/25 11:08:18 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*make_stack(int content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->info = malloc(sizeof(t_turk_node));
	if (!ptr->info)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void	stack_clear(t_list **lst)
{
	t_list	*temp;

	if (lst && *lst)
	{
		while ((*lst))
		{
			if ((*lst)->next)
			{
				temp = (*lst)->next;
				free((*lst)->info);
				free(*lst);
				*lst = temp;
			}
			else
			{
				free((*lst)->info);
				free(*lst);
				break ;
			}
		}
	}
}

int	stack_add_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && new)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			temp = *lst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		return (1);
	}
	return (0);
}
