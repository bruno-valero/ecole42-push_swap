/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_calculate_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:29:01 by valero            #+#    #+#             */
/*   Updated: 2025/08/30 18:11:11 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_calculate_stack_push_cost(
			t_push_swap *push_swap, int is_on_stack_a)
{
	t_stack_node	*top;
	t_stack_node	*bot;
	t_stack			*stack;
	int				idx;

	if (is_on_stack_a)
		stack = push_swap->stack_a->stack;
	else
		stack = push_swap->stack_b->stack;
	top = stack->top;
	bot = stack->bottom;
	idx = -1;
	while (++idx <= (stack->length / 2))
	{
		turk_calculate_push_cost(top);
		if (top != bot)
			turk_calculate_push_cost(bot);
		top = top->prev;
		bot = bot->next;
	}
}
