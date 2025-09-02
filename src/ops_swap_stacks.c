/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:10:19 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:00:21 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack(t_ps_stack *ps_stack)
{
	if (!ps_stack || !ps_stack->stack
		|| !ps_stack->stack->swap_first_node(ps_stack->stack))
		return (0);
	if (ps_stack->is_stack_a)
		return (!!write(1, "sa\n", 3));
	return (!!write(1, "sb\n", 3));
}

int	swap_stack_both(t_push_swap *push_swap)
{
	if (!push_swap || !push_swap->stack_a || !push_swap->stack_a->stack
		|| !push_swap->stack_b || !push_swap->stack_b->stack)
		return (0);
	if (!push_swap->stack_a->is_stack_a || push_swap->stack_b->is_stack_a)
		return (0);
	if (!push_swap->stack_a->stack->swap_first_node(push_swap->stack_a->stack))
		return (0);
	if (!push_swap->stack_b->stack->swap_first_node(push_swap->stack_b->stack))
	{
		push_swap->stack_a->stack->swap_first_node(push_swap->stack_a->stack);
		return (0);
	}
	return (!!write(1, "ss\n", 3));
}

int	push_stack1_to_stack2(t_push_swap *push_swap, int push_a_to_b)
{
	int	transfer_succeeded;

	if (!push_swap || !push_swap->stack_a || !push_swap->stack_a->stack
		|| !push_swap->stack_b || !push_swap->stack_b->stack)
		return (0);
	if (!push_swap->stack_a->is_stack_a || push_swap->stack_b->is_stack_a)
		return (0);
	if (push_a_to_b)
	{
		transfer_succeeded = push_swap->stack_a->stack->transfer_top(
				push_swap->stack_a->stack, push_swap->stack_b->stack);
		if (!transfer_succeeded)
			return (0);
		push_swap->stack_a->update_on_transfer(
			push_swap->stack_a, push_swap->stack_b);
		return (!!write(1, "pb\n", 3));
	}
	transfer_succeeded = push_swap->stack_b->stack->transfer_top(
			push_swap->stack_b->stack, push_swap->stack_a->stack);
	if (!transfer_succeeded)
		return (0);
	push_swap->stack_b->update_on_transfer(
		push_swap->stack_b, push_swap->stack_a);
	return (!!write(1, "pa\n", 3));
}
