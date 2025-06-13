/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:22:06 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/12 13:56:28 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	stack_len(t_stack_node *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_biggest_node(t_stack_node *stack)
{
	t_stack_node	*biggest;

	if (!stack)
		return (NULL);
	biggest = stack;
	stack = stack->next;
	while (stack)
	{
		if (biggest->nbr < stack->nbr)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}
