/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:49:41 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/23 14:08:23 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_result;

	a = NULL;
	b = NULL;
	split_result = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		init_stack_a(&a, split_result, true);
	}
	else if (argc > 2)
		init_stack_a(&a, argv + 1, false);
	start_sorting(&a, &b);
	free_stack(&b);
	free_split(split_result);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
