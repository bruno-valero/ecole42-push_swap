/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_lower_cost_node.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:50:29 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 22:48:32 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_lower_cost_node(t_stack_node *node, t_push_swap *push_swap, int is_pb)
{
	t_stack_node	*self;
	t_stack_node	*target;

	// contentof(node)
	if (is_pb)
	{
		if (is_both_above_center(node))
		{
			while ()
			{
				push_swap->ops->rr(push_swap);
			}
		}
		else if (is_both_below_center(node))
		{

		}
		else if (is_above_center(node))
		{

		}
		else
		{

		}
	}
}
