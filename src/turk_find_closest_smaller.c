/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_closest_smaller.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:41:32 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 19:58:32 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_closest_smaller(t_stack_node *curr_node,
				t_find_closest_temps *temps, t_find_closest_result *result);

t_find_closest_result	turk_find_closest_smaller(t_stack_node *node,
					t_ps_stack *stack, t_stack_node *temp_node)
{
	t_find_closest_result	result;
	t_find_closest_temps	temps;

	init_temps(&temps, stack);
	temp_node = stack_new_node(new_ps_node_content(INT_MAX));
	result.value = temp_node;
	while (temps.back_idx >= (int)(stack->stack->length / 2))
	{
		if (is_smaller(temps.top, node) && is_bigger(temps.top, result.value))
			change_closest_smaller(temps.top, &temps, &result);
		if (temps.bot != temps.top && is_smaller(temps.bot, node)
			&& is_bigger(temps.bot, result.value))
			change_closest_smaller(temps.bot, &temps, &result);
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

static void	change_closest_smaller(t_stack_node *curr_node,
					t_find_closest_temps *temps, t_find_closest_result *result)
{
	int	index;

	if (curr_node == temps->top)
		index = temps->front_idx;
	else
		index = temps->back_idx;
	if (((!index || index == temps->stack_length - 1)
			&& contentof(result->value)->value == INT_MIN))
		stack_delete_node(&result->value, ps_node_content_destroy);
	result->value = curr_node;
	result->index = index;
	result->succeed = 1;
}
