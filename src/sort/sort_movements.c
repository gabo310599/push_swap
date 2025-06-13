/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:56:11 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/13 22:08:01 by gojeda           ###   ########.fr       */
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
