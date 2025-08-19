/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:10:19 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/19 15:01:58 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack(t_ps_stack *push_swap)
{
	if (!push_swap || !push_swap->stack
		|| !push_swap->stack->swap_first_node(push_swap->stack))
		return (0);
	if (push_swap->is_stack_a)
		return (!!write(1, "sa\n", 3));
	return (!!write(1, "sb\n", 3));
}

int	swap_stack_both(t_ps_stack *push_swap_a, t_ps_stack *push_swap_b)
{
	if (!push_swap_a || !push_swap_a->stack
		|| !push_swap_b || !push_swap_b->stack)
		return (0);
	if (!push_swap_a->is_stack_a || push_swap_b->is_stack_a)
		return (0);
	if (!push_swap_a->stack->swap_first_node(push_swap_a->stack))
		return (0);
	if (!push_swap_b->stack->swap_first_node(push_swap_b->stack))
	{
		push_swap_a->stack->swap_first_node(push_swap_a->stack);
		return (0);
	}
	return (!!write(1, "ss\n", 3));
}

int	stack1_push_to_stack2(
		t_ps_stack *push_swap_a, t_ps_stack *push_swap_b, int push_a_to_b)
{
	if (!push_swap_a || !push_swap_a->stack
		|| !push_swap_b || !push_swap_b->stack)
		return (0);
	if (!push_swap_a->is_stack_a || push_swap_b->is_stack_a)
		return (0);
	if (push_a_to_b)
	{
		if (!push_swap_a->stack->transfer_top(
				push_swap_a->stack, push_swap_b->stack))
			return (0);
		return (!!write(1, "pb\n", 3));
	}
	if (!push_swap_b->stack->transfer_top(
			push_swap_b->stack, push_swap_a->stack))
		return (0);
	return (!!write(1, "pa\n", 3));
}
