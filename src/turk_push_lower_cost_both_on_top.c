/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_lower_cost_both_on_top.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:50:29 by valero            #+#    #+#             */
/*   Updated: 2025/08/30 18:41:48 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_thebothabove_on_top(t_stack_node *node, t_stack *self_stack,
				t_stack *other_stack, t_push_swap *push_swap);
static void	put_thebothabelow_on_top(t_stack_node *node, t_stack *self_stack,
				t_stack *other_stack, t_push_swap *push_swap);
static void	put_theaabove_on_top(t_stack_node *node, t_stack *self_stack,
				t_stack *other_stack, t_push_swap *push_swap);
static void	put_theabelow_on_top(t_stack_node *node, t_stack *self_stack,
				t_stack *other_stack, t_push_swap *push_swap);

void	turk_put_both_on_top(t_stack_node *node,
			t_push_swap *push_swap, int is_on_stack_a)
{
	t_stack	*self_stack;
	t_stack	*other_stack;

	if (is_on_stack_a)
	{
		self_stack = push_swap->stack_a->stack;
		other_stack = push_swap->stack_b->stack;
	}
	else
	{
		self_stack = push_swap->stack_b->stack;
		other_stack = push_swap->stack_a->stack;
	}
	if (is_both_above_center(node))
		put_thebothabove_on_top(node, self_stack, other_stack, push_swap);
	else if (is_both_below_center(node))
		put_thebothabelow_on_top(node, self_stack, other_stack, push_swap);
	else if (is_above_center(node))
		put_theaabove_on_top(node, self_stack, other_stack, push_swap);
	else
		put_theabelow_on_top(node, self_stack, other_stack, push_swap);
}

static void	put_thebothabove_on_top(t_stack_node *node, t_stack *self_stack,
				t_stack *other_stack, t_push_swap *push_swap)
{
	int		is_self_on_top;
	int		is_other_on_top;

	is_self_on_top = node == self_stack->top;
	is_other_on_top = contentof(node)->target_node == other_stack->top;
	while (!is_self_on_top || !is_other_on_top)
	{
		push_swap->ops->rr(push_swap);
		is_self_on_top = node == self_stack->top;
		is_other_on_top = contentof(node)->target_node == other_stack->top;
	}
	while (!is_self_on_top)
	{
		push_swap->ops->ra(push_swap);
		is_self_on_top = node == self_stack->top;
	}
	while (!is_other_on_top)
	{
		push_swap->ops->rb(push_swap);
		is_other_on_top = contentof(node)->target_node == other_stack->top;
	}
}

static void	put_thebothabelow_on_top(t_stack_node *node, t_stack *self_stack,
				t_stack *other_stack, t_push_swap *push_swap)
{
	int		is_self_on_top;
	int		is_other_on_top;

	is_self_on_top = node == self_stack->top;
	is_other_on_top = contentof(node)->target_node == other_stack->top;
	while (!is_self_on_top || !is_other_on_top)
	{
		push_swap->ops->rrr(push_swap);
		is_self_on_top = node == self_stack->top;
		is_other_on_top = contentof(node)->target_node == other_stack->top;
	}
	while (!is_self_on_top)
	{
		push_swap->ops->rra(push_swap);
		is_self_on_top = node == self_stack->top;
	}
	while (!is_other_on_top)
	{
		push_swap->ops->rrb(push_swap);
		is_other_on_top = contentof(node)->target_node == other_stack->top;
	}
}

static void	put_theaabove_on_top(t_stack_node *node, t_stack *self_stack,
				t_stack *other_stack, t_push_swap *push_swap)
{
	int		is_self_on_top;
	int		is_other_on_top;

	is_self_on_top = node == self_stack->top;
	is_other_on_top = contentof(node)->target_node == other_stack->top;
	while (!is_self_on_top)
	{
		push_swap->ops->ra(push_swap);
		is_self_on_top = node == self_stack->top;
	}
	while (!is_other_on_top)
	{
		push_swap->ops->rrb(push_swap);
		is_other_on_top = contentof(node)->target_node == other_stack->top;
	}
}

static void	put_theabelow_on_top(t_stack_node *node, t_stack *self_stack,
				t_stack *other_stack, t_push_swap *push_swap)
{
	int		is_self_on_top;
	int		is_other_on_top;

	is_self_on_top = node == self_stack->top;
	is_other_on_top = contentof(node)->target_node == other_stack->top;
	while (!is_self_on_top)
	{
		push_swap->ops->rra(push_swap);
		is_self_on_top = node == self_stack->top;
	}
	while (!is_other_on_top)
	{
		push_swap->ops->rb(push_swap);
		is_other_on_top = contentof(node)->target_node == other_stack->top;
	}
}
