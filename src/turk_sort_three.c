/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:13:52 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/31 21:51:53 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_ps_stack	*ps_stack, t_push_swap *push_swap);
static int	rotate_reverse(t_ps_stack	*ps_stack, t_push_swap *push_swap);
static int	swap(t_ps_stack	*ps_stack, t_push_swap *push_swap);
static int	node_value(t_stack *stack, int index);

int	turk_sort_three(t_ts_stack *self, t_push_swap *push_swap)
{
	t_ps_stack	*ps_stack;
	t_stack		*stack;

	ps_stack = self->ps_stack;
	stack = ps_stack->stack;
	if (!self || !ps_stack || stack->length != 3)
		return (0);
	if (node_value(stack, 0) == ps_stack->bigger)
		rotate(ps_stack, push_swap);
	else if (node_value(stack, 1) == ps_stack->bigger)
		rotate_reverse(ps_stack, push_swap);
	if (node_value(stack, 0) > node_value(stack, 1))
		swap(ps_stack, push_swap);
	return (1);
}

static int	rotate(t_ps_stack	*ps_stack, t_push_swap *push_swap)
{
	if (ps_stack->is_stack_a)
		push_swap->ops->ra(push_swap);
	else
		push_swap->ops->rb(push_swap);
	return (1);
}

static int	rotate_reverse(t_ps_stack	*ps_stack, t_push_swap *push_swap)
{
	if (ps_stack->is_stack_a)
		push_swap->ops->rra(push_swap);
	else
		push_swap->ops->rrb(push_swap);
	return (1);
}

static int	swap(t_ps_stack	*ps_stack, t_push_swap *push_swap)
{
	if (ps_stack->is_stack_a)
		push_swap->ops->sa(push_swap);
	else
		push_swap->ops->sb(push_swap);
	return (1);
}

static int	node_value(t_stack *stack, int index)
{
	if (!index)
		return (contentof(stack->top)->value);
	else if (index == 1)
		return (contentof(stack->top->prev)->value);
	return (contentof(stack->bottom)->value);
}
