/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:13:52 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/23 16:15:46 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_ps_stack	*ps_stack, t_push_swap *push_swap);
static int	rotate_reverse(t_ps_stack	*ps_stack, t_push_swap *push_swap);
static int	swap(t_ps_stack	*ps_stack, t_push_swap *push_swap);

int	turk_sort_three(t_ts_stack *self, t_push_swap *push_swap)
{
	t_ps_stack	*ps_stack;
	t_stack		*stack;

	ps_stack = self->ps_stack;
	stack = ps_stack->stack;
	if (!self || !ps_stack || stack->length != 3)
		return (0);
	if (ps_stack->bigger == ps_stack->get_content(stack->top)->value)
		rotate(ps_stack, push_swap);
	if (ps_stack->get_content(stack->top)->value
		> ps_stack->get_content(stack->top->prev)->value)
		swap(ps_stack, push_swap);
	if (ps_stack->bigger == ps_stack->get_content(stack->top->prev)->value)
	{
		if (ps_stack->smaller == ps_stack->get_content(stack->bottom)->value)
			return (rotate_reverse(ps_stack, push_swap));
		swap(ps_stack, push_swap);
		rotate(ps_stack, push_swap);
	}
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
		push_swap->ops->ra(push_swap);
	else
		push_swap->ops->rb(push_swap);
	return (1);
}
