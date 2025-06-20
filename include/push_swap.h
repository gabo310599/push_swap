/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:46:46 by gojeda            #+#    #+#             */
/*   Updated: 2025/06/20 23:53:03 by gojeda           ###   ########.fr       */
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
int				error_syntax(char *s);
void			free_errors(t_stack_node **a, char **split_result);
void			free_stack(t_stack_node **stack);
int				is_duplicate(t_stack_node *a, int n);

/***************************************************************************/
//Funciones auxiliares de stacks
/***************************************************************************/
t_stack_node	*find_last_node(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
t_stack_node	*find_biggest_node(t_stack_node *stack);
size_t			stack_len(t_stack_node *stack);
t_stack_node	*find_smallest_node(t_stack_node *stack);
void			start_sorting(t_stack_node *a, t_stack_node *b);
void			free_split(char **split);

/***************************************************************************/
//Funciones inicializar de stacks
/***************************************************************************/
int				init_stack_a(t_stack_node **a, char **argv);
void			set_node_index(t_stack_node *stack);
void			set_cheapest_node(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_cheapest_node(t_stack_node *stack);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

/***************************************************************************/
//Funciones para los movimientos de stacks
/***************************************************************************/
void			sa(t_stack_node **a, bool msg);
void			sb(t_stack_node **b, bool msg);
void			ss(t_stack_node **a, t_stack_node **b, bool msg);
void			pa(t_stack_node **a, t_stack_node **b, bool msg);
void			pb(t_stack_node **a, t_stack_node **b, bool msg);
void			ra(t_stack_node **a, bool msg);
void			rb(t_stack_node **b, bool msg);
void			rr(t_stack_node **a, t_stack_node **b, bool msg);
void			rra(t_stack_node **a, bool msg);
void			rrb(t_stack_node **b, bool msg);
void			rrr(t_stack_node **a, t_stack_node **b, bool msg);

/***************************************************************************/
//Funciones para organizar los stacks
/***************************************************************************/
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node,
					char name);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			push_two_out_of_order(t_stack_node **a, t_stack_node **b);
#endif