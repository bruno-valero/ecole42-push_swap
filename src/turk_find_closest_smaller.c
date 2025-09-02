/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_closest_smaller.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:41:32 by valero            #+#    #+#             */
/*   Updated: 2025/09/02 13:05:52 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_find_closest_result	turk_find_closest_smaller(t_stack_node *node,
					t_ps_stack *stack, t_stack_node *temp_node)
{
	t_find_closest_result	result;
	t_find_closest_temps	temps;

	init_temps(&temps, stack);
	temp_node = stack_new_node(new_ps_node_content(INT_MIN));
	result.value = temp_node;
	while (temps.back_idx >= (int)(stack->stack->length / 2))
	{
		if (is_smaller(temps.top, node) && is_bigger(temps.top, result.value))
			turk_change_closest(temps.top, &temps, &result);
		if (temps.bot != temps.top && is_smaller(temps.bot, node)
			&& is_bigger(temps.bot, result.value))
			turk_change_closest(temps.bot, &temps, &result);
		fill_get_closest_result(&temps, &result, stack);
		continue_loop(&temps);
	}
	if (result.value == temp_node)
		result.succeed = 0;
	if (temp_node)
		stack_delete_node(&temp_node, ps_node_content_destroy);
	return (result);
}
