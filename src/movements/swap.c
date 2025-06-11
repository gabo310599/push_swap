/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:14:07 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/11 21:43:06 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack_node **a, bool msg)
{
	swap(a);
	if (msg)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool msg)
{
	swap(b);
	if (msg)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool msg)
{
	swap(a);
	swap(b);
	if (msg)
		ft_printf("ss\n");
}
