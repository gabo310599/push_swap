/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:46:46 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/10 17:17:51 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

/***************************************************************************/
//Estructuras para los stacks
/***************************************************************************/
typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/***************************************************************************/
//Funciones de manejo de errores
/***************************************************************************/
int		error_syntax(char *s);
void	free_errors(t_stack_node **a);
void	free_stack(t_stack_node **stack);
int		is_duplicate(t_stack_node *a, int n);
#endif