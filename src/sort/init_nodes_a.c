/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:18:56 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/20 23:10:39 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_node_index(t_stack_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_targets_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*b_aux;
	t_stack_node	*target_node;
	long			best_match_value;

	while (a)
	{
		best_match_value = LONG_MIN;
		b_aux = b;
		target_node = NULL;
		while (b_aux)
		{
			if ((b_aux->nbr < a->nbr) && (best_match_value < b_aux->nbr))
			{
				best_match_value = b_aux->nbr;
				target_node = b_aux;
			}
			b_aux = b_aux->next;
		}
		if (best_match_value == LONG_MIN)
			a->target_node = find_biggest_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	calculate_push_cost_a(t_stack_node *a, size_t size_a, size_t size_b)
{
	int		cost_a;
	int		cost_b;

	while (a)
	{
		cost_a = a->index;
		cost_b = a->target_node->index;
		if (!a->above_median)
			cost_a = (int)size_a - a->index;
		if (!a->target_node->above_median)
			cost_b = (int)size_b - a->target_node->index;
		if (a->above_median == a->target_node->above_median)
		{
			if (cost_a > cost_b)
				a->push_cost = cost_a;
			else
				a->push_cost = cost_b;
		}
		else
			a->push_cost = cost_a + cost_b;
		a = a->next;
	}
}

void	set_cheapest_node(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_node_index(a);
	set_node_index(b);
	set_targets_a(a, b);
	calculate_push_cost_a(a, stack_len(a), stack_len(b));
	set_cheapest_node(a);
}
