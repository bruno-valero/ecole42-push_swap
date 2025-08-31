/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_closest_bigger.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:10:27 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/30 16:55:19 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_find_closest_result	turk_find_closest_bigger(t_stack_node *node,
					t_ps_stack *stack, t_stack_node *temp_node)
{
	t_find_closest_result	result;
	t_find_closest_temps	temps;

	init_temps(&temps, stack);
	temp_node = stack_new_node(new_ps_node_content(INT_MAX));
	result.value = temp_node;
	while (temps.back_idx >= (int)(stack->stack->length / 2))
	{
		if (is_bigger(temps.top, node) && is_smaller(temps.top, result.value))
			turk_change_closest(temps.top, &temps, &result);
		if (temps.bot != temps.top && is_bigger(temps.bot, node)
			&& is_smaller(temps.bot, result.value))
			turk_change_closest(temps.bot, &temps, &result);
		fill_get_closest_result(&temps, &result, stack);
		continue_loop(&temps);
	}
	if (result.value == temp_node)
	{
		stack_delete_node(&temp_node, ps_node_content_destroy);
		result.succeed = 0;
	}
	return (result);
}
