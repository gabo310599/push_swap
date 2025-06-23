/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:18:04 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/23 22:44:38 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../include/push_swap.h"

void	free_instructions(char **instructions);
char	**control_stdin(void);
char	**append_line(char **lines, char *line, size_t *count,
			size_t *capacity);
bool	process_instruction(char *instruction, t_stack_node **a,
			t_stack_node **b);
void	free_everything(t_stack_node **a, t_stack_node **b,
			char **instructions);
void	exit_with_error(t_stack_node **a, t_stack_node **b,
			char **instructions);
void	check_instructions(char **instructions, t_stack_node **a,
			t_stack_node **b);
#endif