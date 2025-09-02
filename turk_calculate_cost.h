/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_calculate_cost.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:56:56 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 18:57:42 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_CALCULATE_COST_H
# define TURK_CALCULATE_COST_H

typedef struct s_stack_node	t_stack_node;

int		is_above_center(t_stack_node *node);
int		is_both_above_center(t_stack_node *node);
int		is_both_below_center(t_stack_node *node);
void	turk_calculate_push_cost(t_stack_node *node);
void	turk_calculate_stack_push_cost(
			t_push_swap *push_swap, int is_on_stack_a);

#endif
