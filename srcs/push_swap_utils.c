/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 06:53:00 by alusnia           #+#    #+#             */
/*   Updated: 2025/11/14 06:53:00 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c)
{
	t_list		*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	if (c != 's')
		ft_printf("s%c\n", c);
}

void	sswap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	ft_printf("ss\n");
}

void	push(t_list **from, t_list **to, t_turk_info **t_info, char c)
{
	t_list	*temp;

	if (!from)
		return ;
	if (c == 'a')
	{
		(*t_info)->stack_a_len++;
		(*t_info)->stack_b_len--;
	}
	else if (c == 'b')
	{
		(*t_info)->stack_a_len--;
		(*t_info)->stack_b_len++;
	}
	temp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = temp;
	ft_printf("p%c\n", c);
}
