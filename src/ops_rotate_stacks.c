/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:31:24 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/21 01:26:07 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_ps_stack *ps_sptack)
{
	if (!ps_sptack || !ps_sptack->stack
		|| !ps_sptack->stack->rotate(ps_sptack->stack, 0))
		return (0);
	if (ps_sptack->is_stack_a)
		return (!!write(1, "ra\n", 3));
	return (!!write(1, "rb\n", 3));
}

int	rotate_stack_both(t_push_swap	*push_swap)
{
	if (!push_swap || !push_swap->stack_a || !push_swap->stack_a->stack
		|| !push_swap->stack_b || !push_swap->stack_b->stack)
		return (0);
	if (!push_swap->stack_a->is_stack_a || push_swap->stack_b->is_stack_a)
		return (0);
	if (!push_swap->stack_a->stack->rotate(push_swap->stack_a->stack, 0))
		return (0);
	if (!push_swap->stack_b->stack->rotate(push_swap->stack_b->stack, 0))
	{
		push_swap->stack_a->stack->rotate(push_swap->stack_a->stack, 1);
		return (0);
	}
	return (!!write(1, "rr\n", 3));
}

int	rotate_reverse_stack(t_ps_stack *ps_stack)
{
	if (!ps_stack || !ps_stack->stack
		|| !ps_stack->stack->rotate(ps_stack->stack, 1))
		return (0);
	if (ps_stack->is_stack_a)
		return (!!write(1, "rra\n", 4));
	return (!!write(1, "rrb\n", 4));
}

int	rotate_reverse_stack_both(t_push_swap	*push_swap)
{
	if (!push_swap || !push_swap->stack_a || !push_swap->stack_a->stack
		|| !push_swap->stack_b || !push_swap->stack_b->stack)
		return (0);
	if (!push_swap->stack_a->is_stack_a || push_swap->stack_b->is_stack_a)
		return (0);
	if (!push_swap->stack_a->stack->rotate(push_swap->stack_a->stack, 1))
		return (0);
	if (!push_swap->stack_b->stack->rotate(push_swap->stack_b->stack, 1))
	{
		push_swap->stack_a->stack->rotate(push_swap->stack_a->stack, 0);
		return (0);
	}
	return (!!write(1, "rrr\n", 3));
}
