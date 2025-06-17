/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:14:12 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/16 14:41:56 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*node_a;
	t_stack_node	*target_node;
	long			best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		node_a = a;
		while (node_a)
		{
			if (node_a->nbr > b->nbr && node_a->nbr < best_match_value)
			{
				best_match_value = node_a->nbr;
				target_node = node_a;
			}
			node_a = node_a->next;
		}
		if (best_match_value == LONG_MAX)
			b->target_node = find_smallest_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_node_index(a);
	set_node_index(b);
	set_target_b(a, b);
}
