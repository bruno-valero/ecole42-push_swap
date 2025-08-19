/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:31:24 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/19 15:22:59 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_ps_stack *push_swap)
{
	if (!push_swap || !push_swap->stack
		|| !push_swap->stack->rotate(push_swap, 0))
		return (0);
	if (push_swap->is_stack_a)
		return (!!write(1, "ra\n", 3));
	return (!!write(1, "rb\n", 3));
}

int	rotate_stack_both(t_ps_stack *push_swap_a, t_ps_stack *push_swap_b)
{
	if (!push_swap_a || !push_swap_a->stack
		|| !push_swap_b || !push_swap_b->stack)
		return (0);
	if (!push_swap_a->is_stack_a || push_swap_b->is_stack_a)
		return (0);
	if (!push_swap_a->stack->rotate(push_swap_a, 0))
		return (0);
	if (!push_swap_b->stack->rotate(push_swap_b, 0))
	{
		push_swap_a->stack->rotate(push_swap_a, 1);
		return (0);
	}
	return (!!write(1, "rr\n", 3));
}

int	rotate_reverse_stack(t_ps_stack *push_swap)
{
	if (!push_swap || !push_swap->stack
		|| !push_swap->stack->rotate(push_swap->stack, 1))
		return (0);
	if (push_swap->is_stack_a)
		return (!!write(1, "rra\n", 4));
	return (!!write(1, "rrb\n", 4));
}

int	rotate_reverse_stack_both(t_ps_stack *push_swap_a, t_ps_stack *push_swap_b)
{
	if (!push_swap_a || !push_swap_a->stack
		|| !push_swap_b || !push_swap_b->stack)
		return (0);
	if (!push_swap_a->stack->rotate(push_swap_a, 1))
		return (0);
	if (!push_swap_b->stack->rotate(push_swap_b, 1))
	{
		push_swap_a->stack->rotate(push_swap_a, 0);
		return (0);
	}
	return (!!write(1, "rrr\n", 3));
}
