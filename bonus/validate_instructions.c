/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:19:24 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/23 22:10:37 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	strip_newline(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

char	**append_line(char **lines, char *line, size_t *count, size_t *capacity)
{
	char	**tmp;
	size_t	new_capacity;

	new_capacity = *capacity + 2;
	tmp = ft_realloc(lines, *capacity * sizeof(char *),
			new_capacity * sizeof(char *));
	if (!tmp)
	{
		free(line);
		while (*count)
			free(lines[--(*count)]);
		free(lines);
		return (NULL);
	}
	lines = tmp;
	lines[*count] = line;
	lines[++(*count)] = NULL;
	*capacity = new_capacity;
	return (lines);
}

char	**control_stdin(void)
{
	char	*line;
	char	**lines;
	size_t	count;
	size_t	capacity;

	lines = NULL;
	count = 0;
	capacity = 0;
	line = get_next_line(0);
	while (line)
	{
		strip_newline(line);
		lines = append_line(lines, line, &count, &capacity);
		if (!lines)
			return (NULL);
		line = get_next_line(0);
	}
	return (lines);
}

void	free_instructions(char **instructions)
{
	size_t	i;

	i = 0;
	if (!instructions)
		return ;
	while (instructions[i])
		free(instructions[i++]);
	free(instructions);
}

bool	process_instruction(char *instruction, t_stack_node **a, t_stack_node **b)
{
	if (ft_strncmp(instruction, "sa", 2) == 0 && ft_strlen(instruction) == 2)
		return (sa(a, false), true);
	if (ft_strncmp(instruction, "sb", 2) == 0 && ft_strlen(instruction) == 2)
		return (sb(b, false), true);
	if (ft_strncmp(instruction, "ss", 2) == 0 && ft_strlen(instruction) == 2)
		return (ss(a, b, false), true);
	if (ft_strncmp(instruction, "pa", 2) == 0 && ft_strlen(instruction) == 2)
		return (pa(a, b, false), true);
	if (ft_strncmp(instruction, "pb", 2) == 0 && ft_strlen(instruction) == 2)
		return (pb(b, a, false), true);
	if (ft_strncmp(instruction, "ra", 2) == 0 && ft_strlen(instruction) == 2)
		return (ra(a, false), true);
	if (ft_strncmp(instruction, "rb", 2) == 0 && ft_strlen(instruction) == 2)
		return (rb(b, false), true);
	if (ft_strncmp(instruction, "rr", 2) == 0 && ft_strlen(instruction) == 2)
		return (rr(a, b, false), true);
	if (ft_strncmp(instruction, "rra", 3) == 0 && ft_strlen(instruction) == 3)
		return (rra(a, false), true);
	if (ft_strncmp(instruction, "rrb", 3) == 0 && ft_strlen(instruction) == 3)
		return (rrb(b, false), true);
	if (ft_strncmp(instruction, "rrr", 3) == 0 && ft_strlen(instruction) == 3)
		return (rrr(a, b, false), true);
	return (false);
}
