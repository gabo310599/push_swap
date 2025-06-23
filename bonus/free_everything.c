/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 22:22:50 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/23 22:38:35 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_everything(t_stack_node **a, t_stack_node **b,
			char **instructions)
{
	free_stack(a);
	free_stack(b);
	free_instructions(instructions);
}

void	exit_with_error(t_stack_node **a, t_stack_node **b,
			char **instructions)
{
	free_everything(a, b, instructions);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
