/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:47:36 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/11 21:46:07 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*src_aux;

	if (!(*src))
		return ;
	src_aux = *src;
	*src = src_aux->next;
	if (*src)
		(*src)->prev = NULL;
	src_aux->next = *dest;
	if (*dest)
		(*dest)->prev = src_aux;
	src_aux->prev = NULL;
	*dest = src_aux;
}

void	pa(t_stack_node **a, t_stack_node **b, bool msg)
{
	push(a, b);
	if (msg)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool msg)
{
	push(b, a);
	if (msg)
		ft_printf("pb\n");
}
