/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:00:57 by gojeda            #+#    #+#             */
/*   Updated: 2025/07/03 14:56:13 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_result;
	char			**instructions;

	a = NULL;
	b = NULL;
	split_result = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		init_stack_a(&a, split_result, true);
		free_split(split_result);
	}
	else if (argc > 2)
		init_stack_a(&a, argv + 1, false);
	instructions = control_stdin();
	check_instructions(instructions, &a, &b);
	free_everything(&a, &b, instructions);
	return (0);
}
