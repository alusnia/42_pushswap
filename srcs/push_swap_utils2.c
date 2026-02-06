/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alusnia <alusnia@student.42Warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 06:52:57 by alusnia           #+#    #+#             */
/*   Updated: 2025/11/14 06:52:57 by alusnia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, char c)
{
	t_list	*temp;
	t_list	*start;

	start = *stack;
	while ((*stack)->next)
	{
		temp = (*stack);
		(*stack) = (*stack)->next;
	}
	(*stack)->next = start;
	temp->next = NULL;
	if (c != 's')
		ft_printf("rr%c\n", c);
}

void	srotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 's');
	rotate(stack_b, 's');
	ft_printf("rrr\n");
}

void	rrotate(t_list **stack, char c)
{
	t_list	*temp;

	temp = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = temp;
	*stack = (*stack)->next;
	*stack = (*stack)->next;
	temp->next = NULL;
	if (c != 's')
		ft_printf("r%c\n", c);
}

void	srrotate(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a, 's');
	rrotate(stack_b, 's');
	ft_printf("rr\n");
}
