/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:50:56 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/11 22:03:06 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	last = find_last_node(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a, bool msg)
{
	rotate(a);
	if (msg)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool msg)
{
	rotate(b);
	if (msg)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool msg)
{
	rotate(a);
	rotate(b);
	if (msg)
		ft_printf("rr\n");
}
