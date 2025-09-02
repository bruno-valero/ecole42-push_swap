/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_closest_utils_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:52:19 by valero            #+#    #+#             */
/*   Updated: 2025/09/02 13:26:38 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_change_closest(t_stack_node *curr_node,
					t_find_closest_temps *temps, t_find_closest_result *result)
{
	int	index;

	if (curr_node == temps->top)
		index = temps->front_idx;
	else
		index = temps->back_idx;
	result->value = curr_node;
	result->index = index;
	result->succeed = 1;
	contentof(curr_node)->self_index = index;
}
