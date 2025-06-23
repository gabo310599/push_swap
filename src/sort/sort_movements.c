/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:56:11 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/23 22:06:05 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b, true);
	while (*a != cheapest)
		ra(a, true);
	while (*b != cheapest->target_node)
		rb(b, true);
	set_node_index(*a);
	set_node_index(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, true);
	while (*a != cheapest)
		rra(a, true);
	while (*b != cheapest->target_node)
		rrb(b, true);
	set_node_index(*a);
	set_node_index(*b);
}

static bool	is_out_of_order(t_stack_node *node)
{
	if (!node || !node->next)
		return (false);
	return (node->nbr > node->next->nbr);
}

void	push_two_out_of_order(t_stack_node **a, t_stack_node **b)
{
	int	pushed;
	int	len;
	int	i;

	pushed = 0;
	len = stack_len(*a);
	i = 0;
	while (pushed < 2 && i < len)
	{
		if (is_out_of_order(*a))
		{
			pb(b, a, true);
			pushed++;
		}
		else
			ra(a, true);
		i++;
	}
}
