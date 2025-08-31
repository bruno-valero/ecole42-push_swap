/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_lower_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:40:31 by valero            #+#    #+#             */
/*   Updated: 2025/08/30 18:48:49 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_lower_cost_node(t_push_swap *push_swap, int is_pb)
{
	t_stack_node	*lower_cost_node;

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
