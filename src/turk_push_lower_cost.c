/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_lower_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:40:31 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:01:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_lower_cost_node(t_push_swap *push_swap, int is_pb)
{
	t_stack_node	*lower_cost_node;

	while (is_pb && push_swap->stack_b->stack->length < 2)
		push_swap->ops->pb(push_swap);
	if (is_pb && push_swap->stack_a->stack->length == 3)
		return (1);
	turk_find_stack_targets(push_swap, is_pb);
	turk_calculate_stack_push_cost(push_swap, is_pb);
	lower_cost_node = find_lower_cost(push_swap, is_pb);
	turk_put_both_on_top(lower_cost_node, push_swap, is_pb);
	if (is_pb)
	{
		push_swap->ops->pb(push_swap);
		return (1);
	}
	push_swap->ops->pa(push_swap);
	return (1);
}
