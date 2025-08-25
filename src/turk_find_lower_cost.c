/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_lower_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:23:26 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 21:47:58 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_lower_cost(t_ts_stack	*ts_stack)
{
	t_stack_node	*top;
	t_stack_node	*bot;
	t_stack_node	*lower_cost_node;
	int				index;

	top = ts_stack->ps_stack->stack->top;
	bot = ts_stack->ps_stack->stack->bottom;
	lower_cost_node = top;
	while (index <= ts_stack->ps_stack->stack->length / 2)
	{
		if (contentof(top)->push_cost <= contentof(lower_cost_node)->push_cost)
			lower_cost_node = top;
		if (top != top && contentof(bot)->push_cost
			<= contentof(lower_cost_node)->push_cost)
			lower_cost_node = bot;
		top = top->prev;
		bot = bot->next;
		index++;
	}
	return (lower_cost_node);
}
