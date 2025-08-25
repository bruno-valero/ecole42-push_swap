/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:00:30 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 19:58:32 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node			*find_ps_bigger_node(
								t_ps_stack *stack, t_stack_node *bigger);
static t_stack_node			*find_ps_smaller_node(
								t_ps_stack *stack, t_stack_node *smaller);

/**
 * # Updates Push Swap Stack values after a Transfer
 *
 * ---
 *
 * Ensures that the `bigger` (maximum) and `smaller` (minimum) values of two
 * stacks remain correct after a push operation where only `other_stack` receives
 * a new top node from `self`.
 *
 * ---
 *
 * ## How it works:
 *
 * 1. Retrieves the top content of `other_stack`
 * (the stack that received the node).
 *
 * 2. Checks if the transferred value was previously the maximum or minimum
 *    of `self`. If so, recalculates `self->bigger` or `self->smaller` by
 *    traversing the stack with `find_ps_bigger_node` or `find_ps_smaller_node`.
 *
 * 3. Updates `other_stack->bigger` and `other_stack->smaller` if the new
 *    top element introduces a new maximum or minimum.
 *
 * ---
 *
 * ## In summary:
 *
 * Keeps both stacks' metadata consistent after a push operation, ensuring
 * accurate tracking of maximum and minimum values even when transferred
 * elements were previously the extremes.
 *
 * ---
 *
 * @param self        The stack from which the node was transferred. Its
 *                    extremes may be recalculated if the transferred node
 *                    was previously its `bigger` or `smaller`.
 * @param other_stack The stack that received the node. Its extremes are
 *                    updated if the new top element changes them.
 *
 * @return This function does not return a value.
 */
void	ps_stack_update_on_transfer(t_ps_stack *self, t_ps_stack *other_stack)
{
	t_ps_node_content	*other_top_content;

	if (!self || !self->stack || !other_stack || !other_stack->stack)
		return ;
	if (other_stack->stack->length == 1)
	{
		other_stack->smaller = INT_MAX;
		other_stack->bigger = INT_MIN;
	}
	other_top_content = contentof(other_stack->stack->top);

	if (self->bigger == other_top_content->value && self->stack->length)
		self->bigger = contentof(find_ps_bigger_node(self, NULL))->value;
	if (self->smaller == other_top_content->value && self->stack->length)
		self->smaller = contentof(find_ps_smaller_node(self, NULL))->value;
	if (!self->stack->length)
	{
		self->smaller = INT_MAX;
		self->bigger = INT_MIN;
	}
	if (other_stack->bigger < other_top_content->value)
		other_stack->bigger = other_top_content->value;
	if (other_stack->smaller > other_top_content->value)
		other_stack->smaller = other_top_content->value;
}

/**
 * # Finds the Largest Node in a Push Swap Stack
 *
 * ---
 *
 * Traverses a `t_ps_stack` to find and return the node with the largest
 * integer value (`bigger`).
 *
 * ---
 *
 * ## How it works:
 *
 * 1. Initializes two pointers: one starting from the top of the stack,
 *    the other from the bottom.
 * 2. Compares the values at both ends against the current `bigger` node.
 * 3. If a larger value is found, updates `bigger` to point to that node.
 * 4. Moves the `top` pointer down (via `prev`) and the `bottom` pointer
 *    up (via `next`) simultaneously.
 * 5. Repeats this process until all elements are checked.
 *
 * ---
 *
 * ## Why both directions?
 *
 * - The function iterates from both ends at once (`top` and `bottom`),
 *   effectively halving the number of iterations needed compared to
 *   a single-direction traversal.
 *
 * ---
 *
 * ## In summary:
 *
 * Efficiently scans a stack from both ends to determine the node with
 * the maximum `value`, returning a pointer to that node.
 *
 * ---
 *
 * @param stack   The push_swap stack where the search is performed.
 * @param bigger  A candidate node, initially set to the top of the stack.
 *
 * ---
 *
 * @return A pointer to the node containing the smallest value in the stack.
 */
static t_stack_node	*find_ps_bigger_node(
		t_ps_stack *stack, t_stack_node *bigger)
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	int				start;
	int				end;

	if (!stack || !stack->stack)
		return (NULL);
	start = 0;
	end = stack->stack->length - 1;
	top = stack->stack->top;
	bottom = stack->stack->bottom;
	bigger = top;
	while (start < end)
	{
		if (contentof(top)->value > contentof(bigger)->value)
			bigger = top;
		if (bottom != top && contentof(bottom)->value
			> contentof(bigger)->value)
			bigger = bottom;
		top = top->prev;
		bottom = bottom->next;
		start++;
		end--;
	}
	return (bigger);
}

/**
 * # Finds the Smallest Node in a Push Swap Stack
 *
 * ---
 *
 * Traverses a `t_ps_stack` to find and return the node with the smallest
 * integer value (`smaller`).
 *
 * ---
 *
 * ## How it works:
 *
 * 1. Initializes two pointers: one starting from the top of the stack,
 *    the other from the bottom.
 * 2. Compares the values at both ends against the current `smaller` node.
 * 3. If a smaller value is found, updates `smaller` to point to that node.
 * 4. Moves the `top` pointer down (via `prev`) and the `bottom` pointer
 *    up (via `next`) simultaneously.
 * 5. Repeats this process until all elements are checked.
 *
 * ---
 *
 * ## Why both directions?
 *
 * - The function iterates from both ends at once (`top` and `bottom`),
 *   effectively halving the number of iterations needed compared to
 *   a single-direction traversal.
 *
 * ---
 *
 * ## In summary:
 *
 * Efficiently scans a stack from both ends to determine the node with
 * the minimum `value`, returning a pointer to that node.
 *
 * ---
 *
 * @param stack    The push_swap stack where the search is performed.
 * @param smaller  A candidate node, initially set to the top of the stack.
 *
 * ---
 *
 * @return A pointer to the node containing the smallest value in the stack.
 */
static t_stack_node	*find_ps_smaller_node(
		t_ps_stack *stack, t_stack_node *smaller)
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	int				start;
	int				end;

	if (!stack || !stack->stack)
		return (NULL);
	start = 0;
	end = stack->stack->length - 1;
	top = stack->stack->top;
	bottom = stack->stack->bottom;
	smaller = top;
	while (start < end)
	{
		if (contentof(top)->value < contentof(smaller)->value)
			smaller = top;
		if (bottom != top && contentof(bottom)->value
			< contentof(smaller)->value)
			smaller = bottom;
		top = top->prev;
		bottom = bottom->next;
		start++;
		end--;
	}
	return (smaller);
}
