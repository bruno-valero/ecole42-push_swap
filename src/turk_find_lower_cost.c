/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_lower_cost.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:23:26 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:01:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*turk_find_lower_cost_loop(t_ps_stack *ps_stack);

t_stack_node	*find_lower_cost(t_push_swap *push_swap, int is_on_stack_a)
{
	t_ps_stack	*ts_stack;

	if (is_on_stack_a)
		ts_stack = push_swap->stack_a;
	else
		ts_stack = push_swap->stack_b;
	return (turk_find_lower_cost_loop(ts_stack));
}

static t_stack_node	*turk_find_lower_cost_loop(t_ps_stack *ps_stack)
{
	t_stack_node	*top;
	t_stack_node	*bot;
	int				idx;
	t_stack_node	*lower_cost_node;

	top = ps_stack->stack->top;
	bot = ps_stack->stack->bottom;
	lower_cost_node = top;
	idx = -1;
	while ((unsigned int)(++idx) <= (ps_stack->stack->length / 2))
	{
		if (contentof(top)->push_cost < contentof(lower_cost_node)->push_cost)
			lower_cost_node = top;
		if (bot != top && contentof(bot)->push_cost
			< contentof(lower_cost_node)->push_cost)
			lower_cost_node = bot;
		top = top->prev;
		bot = bot->next;
	}
	return (lower_cost_node);
}
