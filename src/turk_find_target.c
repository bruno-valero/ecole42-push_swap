/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:45:38 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 22:24:38 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	update_content(t_stack_node *node, t_ts_stack *current_stack,
				t_ts_stack *other_stack, int target_index);

int	find_target_index(t_stack_node *node, t_ts_stack *current_stack,
	t_ts_stack *other_stack)
{
	t_find_closest_result	search_result;
	int						target_index;

	if (!node || !other_stack || !other_stack->ps_stack
		|| !other_stack->ps_stack->stack)
		return (-1);
	if (other_stack->ps_stack->is_stack_a)
	{
		search_result = turk_find_closest_smaller(node, other_stack, NULL);
		if (!search_result.succeed)
			target_index = search_result.bigger_index;
		else
			target_index = search_result.index;
		return (update_content(node, current_stack, other_stack, target_index));
	}
	search_result = turk_find_closest_bigger(node, other_stack, NULL);
	if (!search_result.succeed)
		target_index = search_result.smaller_index;
	else
		target_index = search_result.index;
	return (update_content(node, current_stack, other_stack, target_index));
}

static int	update_content(t_stack_node *node, t_ts_stack *current_stack,
	t_ts_stack *other_stack, int target_index)
{
	t_ps_node_content	*content;

	content = contentof(node);
	content->other_stack_length = other_stack->ps_stack->stack->length;
	content->target_index = target_index;
	content->self_stack_length = current_stack->ps_stack->stack->length;
	return (target_index);
}
