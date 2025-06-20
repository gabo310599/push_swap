/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:52:18 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/20 22:56:14 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void calculate_individual_costs(t_stack_node *a, size_t size_a,
		size_t size_b)
{
	while (a)
	{
		a->cost_a = a->index;
		if (!a->above_median)
			a->cost_a = (int)size_a - a->index;

		a->cost_b = a->target_node->index;
		if (!a->target_node->above_median)
			a->cost_b = (int)size_b - a->target_node->index;

		a = a->next;
	}
}

void calculate_push_cost_a(t_stack_node *a, t_stack_node *b)
{
	size_t size_a = stack_len(a);
	size_t size_b = stack_len(b);

	calculate_individual_costs(a, size_a, size_b);
	while (a)
	{
		if (a->above_median == a->target_node->above_median)
		{
			if (a->cost_a > a->cost_b)
				a->push_cost = a->cost_a;
			else
				a->push_cost = a->cost_b;
		}
		else
		{
			a->push_cost = a->cost_a + a->cost_b;
		}
		a = a->next;
	}
}

