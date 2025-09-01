/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:45:38 by valero            #+#    #+#             */
/*   Updated: 2025/09/01 07:55:00 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	turk_find_stack_targets_loop(t_ts_stack *current_stack,
				t_ts_stack *other_stack);
static int	turk_find_target(t_stack_node *node, int curr_idx,
				t_ts_stack *current_ts_stack, t_ts_stack *other_ts_stack);
static int	update_indexes(t_find_closest_result search_result,
				t_stack_node *curr_node, int curr_idx, int is_stack_a);
static int	update_content(t_stack_node *node, t_stack *current_stack,
				t_stack *other_stack, int target_index);

int	turk_find_stack_targets(t_push_swap *push_swap, int is_on_stack_a)
{
	t_ts_stack			*stack_a;
	t_ts_stack			*stack_b;

	if (!push_swap || !push_swap->stack_a || !push_swap->stack_b
		|| !push_swap->stack_a->stack || !push_swap->stack_b->stack)
		return (0);
	stack_a = push_swap->turk_sort->ts_stack_a;
	stack_b = push_swap->turk_sort->ts_stack_b;
	if (is_on_stack_a)
		return (turk_find_stack_targets_loop(stack_a, stack_b));
	return (turk_find_stack_targets_loop(stack_b, stack_a));
}

static int	turk_find_stack_targets_loop(t_ts_stack *current_stack,
				t_ts_stack *other_stack)
{
	t_stack_node	*top;
	t_stack_node	*bot;
	t_stack			*curr_stack;
	int				idx;

	if (!current_stack || !current_stack->ps_stack
		|| !current_stack->ps_stack->stack || !other_stack
		|| !other_stack->ps_stack || !other_stack->ps_stack->stack)
		return (0);
	curr_stack = current_stack->ps_stack->stack;
	top = curr_stack->top;
	bot = curr_stack->bottom;
	idx = -1;
	while ((unsigned int)(++idx)
		<= (curr_stack->length / 2))
	{
		turk_find_target(top, idx, current_stack, other_stack);
		if (top != bot)
			turk_find_target(bot, curr_stack->length - 1 - idx,
				current_stack, other_stack);
		top = top->prev;
		bot = bot->next;
	}
	return (1);
}

static int	turk_find_target(t_stack_node *node, int curr_idx,
				t_ts_stack *current_ts_stack, t_ts_stack *other_ts_stack)
{
	t_find_closest_result	search_result;
	int						target_index;

	if (!node || !other_ts_stack || !other_ts_stack->ps_stack
		|| !other_ts_stack->ps_stack->stack)
		return (-1);
	if (current_ts_stack->ps_stack->is_stack_a)
	{
		search_result = turk_find_closest_smaller(
				node, other_ts_stack->ps_stack, NULL);
		target_index = update_indexes(search_result, node, curr_idx, 1);
		return (update_content(node, current_ts_stack->ps_stack->stack,
				other_ts_stack->ps_stack->stack, target_index));
	}
	search_result = turk_find_closest_bigger(
			node, other_ts_stack->ps_stack, NULL);
	target_index = update_indexes(search_result, node, curr_idx, 0);
	return (update_content(node, current_ts_stack->ps_stack->stack,
			other_ts_stack->ps_stack->stack, target_index));
}

static int	update_indexes(t_find_closest_result search_result,
				t_stack_node *curr_node, int curr_idx, int is_stack_a)
{
	int	target_index;

	contentof(curr_node)->self_index = curr_idx;
	if (is_stack_a)
	{
		if (!search_result.succeed)
			target_index = search_result.bigger_index;
		else
			target_index = search_result.index;
		return (target_index);
	}
	if (!search_result.succeed)
		target_index = search_result.smaller_index;
	else
		target_index = search_result.index;
	return (target_index);
}

static int	update_content(t_stack_node *node, t_stack *current_stack,
	t_stack *other_stack, int target_index)
{
	t_ps_node_content	*content;

	content = contentof(node);
	content->target_index = target_index;
	content->target_node = find_by_index(target_index, other_stack);
	content->other_stack_length = other_stack->length;
	content->self_stack_length = current_stack->length;
	return (target_index);
}
