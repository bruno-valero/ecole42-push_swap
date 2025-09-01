/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_calculate_cost_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:56:18 by valero            #+#    #+#             */
/*   Updated: 2025/08/31 15:55:25 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_above_center(t_stack_node *node)
{
	return (contentof(node)->self_index
		< (contentof(node)->self_stack_length / 2));
}

int	is_both_above_center(t_stack_node *node)
{
	return (is_above_center(node) && contentof(node)->target_index
		< contentof(node)->other_stack_length / 2);
}

int	is_both_below_center(t_stack_node *node)
{
	return (!is_above_center(node) && !(contentof(node)->target_index
			< contentof(node)->other_stack_length / 2));
}
