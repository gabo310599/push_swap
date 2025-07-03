/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_on_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 21:14:52 by gojeda            #+#    #+#             */
/*   Updated: 2025/07/03 14:57:39 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_instructions(char **instructions, t_stack_node **a,
			t_stack_node **b)
{
	int		i;
	bool	res;

	i = 0;
	if (instructions)
	{
		while (instructions[i])
		{
			res = process_instruction(instructions[i], a, b);
			if (!res)
				exit_with_error(a, b, instructions);
			i++;
		}
	}
	if (stack_len(*b) == 0 && is_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
