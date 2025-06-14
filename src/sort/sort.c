/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:42:59 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/13 22:31:50 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = find_biggest_node(*a);
	if (*a == biggest)
		ra(a, true);
	else if ((*a)->next == biggest)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, true);		
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) > 3 && !is_sorted(*a))
		pb(b, a, true);
	if (stack_len(*a) > 3 && !is_sorted(*a))
		pb(b, a, true);
	while (stack_len(*a) > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		
	}
}
