/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:05:01 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/11 22:14:29 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!(*stack) || !((*stack)->next))
		return ;
	last = find_last_node(*stack);
	first = *stack;
	last->prev->next = NULL;
	*stack = last;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
}

void	rra(t_stack_node **a, bool msg)
{
	reverse_rotate(a);
	if (msg)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool msg)
{
	reverse_rotate(b);
	if (msg)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool msg)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (msg)
		ft_printf("rrr\n");
}
