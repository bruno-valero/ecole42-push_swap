/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_calculate_cost.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:56:56 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 20:59:04 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_CALCULATE_COST_H
# define TURK_CALCULATE_COST_H

typedef struct s_stack_node	t_stack_node;

int	is_above_center(t_stack_node *node);
int	is_both_above_center(t_stack_node *node);
int	is_both_below_center(t_stack_node *node);

#endif
