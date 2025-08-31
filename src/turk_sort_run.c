/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:34:20 by valero            #+#    #+#             */
/*   Updated: 2025/08/30 19:36:42 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*turk_run(t_push_swap *push_swap)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = push_swap->stack_a->stack;
	stack_b = push_swap->stack_b->stack;
	if (stack_a->length == 1)
		return ;
	if (stack_a->length == 2)
	{
		turk_sort_two(push_swap->turk_sort->ts_stack_a, push_swap);
		return ;
	}
	while (stack_a->length > 3)
		push_lower_cost_node(push_swap, 1);
	turk_sort_three(push_swap->turk_sort->ts_stack_a, push_swap);
	while (stack_b->length)
		push_lower_cost_node(push_swap, 0);
}
