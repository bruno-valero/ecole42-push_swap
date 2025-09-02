/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_lower_cost_both_on_top.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:50:29 by valero            #+#    #+#             */
/*   Updated: 2025/09/01 18:41:00 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_put_both_on_top(t_stack_node *node,
			t_push_swap *push_swap, int is_on_stack_a)
{
	t_ps_stack	*self_stack;
	t_ps_stack	*other_stack;

	if (is_on_stack_a)
	{
		self_stack = push_swap->stack_a;
		other_stack = push_swap->stack_b;
	}
	else
	{
		self_stack = push_swap->stack_b;
		other_stack = push_swap->stack_a;
	}
	if (is_both_above_center(node))
		put_thebothabove_on_top(node, self_stack, other_stack, push_swap);
	else if (is_both_below_center(node))
		put_thebothabelow_on_top(node, self_stack, other_stack, push_swap);
	else if (is_above_center(node))
		put_theaabove_on_top(node, self_stack, other_stack);
	else
		put_theabelow_on_top(node, self_stack, other_stack);
}

void	put_thebothabove_on_top(t_stack_node *node, t_ps_stack *self_stack,
				t_ps_stack *other_stack, t_push_swap *push_swap)
{
	int		is_self_on_top;
	int		is_other_on_top;

	is_self_on_top = node == self_stack->stack->top;
	is_other_on_top = contentof(node)->target_node == other_stack->stack->top;
	while (!is_self_on_top && !is_other_on_top)
	{
		push_swap->ops->rr(push_swap);
		is_self_on_top = node == self_stack->stack->top;
		is_other_on_top = contentof(node)->target_node
			== other_stack->stack->top;
	}
	while (!is_self_on_top)
	{
		rotate_stack(self_stack);
		is_self_on_top = node == self_stack->stack->top;
	}
	while (!is_other_on_top)
	{
		rotate_stack(other_stack);
		is_other_on_top = contentof(node)->target_node
			== other_stack->stack->top;
	}
}

void	put_thebothabelow_on_top(t_stack_node *node, t_ps_stack *self_stack,
				t_ps_stack *other_stack, t_push_swap *push_swap)
{
	int		is_self_on_top;
	int		is_other_on_top;

	is_self_on_top = node == self_stack->stack->top;
	is_other_on_top = contentof(node)->target_node == other_stack->stack->top;
	while (!is_self_on_top && !is_other_on_top)
	{
		push_swap->ops->rrr(push_swap);
		is_self_on_top = node == self_stack->stack->top;
		is_other_on_top = contentof(node)->target_node
			== other_stack->stack->top;
	}
	while (!is_self_on_top)
	{
		rotate_reverse_stack(self_stack);
		is_self_on_top = node == self_stack->stack->top;
	}
	while (!is_other_on_top)
	{
		rotate_reverse_stack(other_stack);
		is_other_on_top = contentof(node)->target_node
			== other_stack->stack->top;
	}
}

void	put_theaabove_on_top(t_stack_node *node, t_ps_stack *self_stack,
				t_ps_stack *other_stack)
{
	int		is_self_on_top;
	int		is_other_on_top;

	is_self_on_top = node == self_stack->stack->top;
	is_other_on_top = contentof(node)->target_node == other_stack->stack->top;
	while (!is_self_on_top)
	{
		rotate_stack(self_stack);
		is_self_on_top = node == self_stack->stack->top;
	}
	while (!is_other_on_top)
	{
		rotate_reverse_stack(other_stack);
		is_other_on_top = contentof(node)->target_node
			== other_stack->stack->top;
	}
}

void	put_theabelow_on_top(t_stack_node *node, t_ps_stack *self_stack,
				t_ps_stack *other_stack)
{
	int		is_self_on_top;
	int		is_other_on_top;

	is_self_on_top = node == self_stack->stack->top;
	is_other_on_top = contentof(node)->target_node == other_stack->stack->top;
	while (!is_self_on_top)
	{
		rotate_reverse_stack(self_stack);
		is_self_on_top = node == self_stack->stack->top;
	}
	while (!is_other_on_top)
	{
		rotate_stack(other_stack);
		is_other_on_top = contentof(node)->target_node
			== other_stack->stack->top;
	}
}
