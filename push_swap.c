/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:49:41 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/21 00:12:39 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_result;
	int				error;

	a = NULL;
	b = NULL;
	split_result = NULL;
	error = 1;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		error = init_stack_a(&a, split_result);
	}
	else if (argc > 2)
		error = init_stack_a(&a, argv + 1);
	if (!error)
		start_sorting(a, b);
	free_split(split_result);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
