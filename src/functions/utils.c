/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:27:01 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/23 13:06:34 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	start_sorting(t_stack_node **a, t_stack_node **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, true);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		i++;
	while (i)
		free(split[--i]);
	free(split);
}
