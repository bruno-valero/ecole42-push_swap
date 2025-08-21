/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:45:50 by valero            #+#    #+#             */
/*   Updated: 2025/08/20 22:23:31 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include "libft.h"

typedef struct s_ps_stack
{
	int					is_stack_a;
	int					bigger;
	int					smaller;
	t_stack				*stack;
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
	 * 1. Retrieves the top content of `other_stack` (the stack that received the node).
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
	void 				(*update_on_transfer)(t_ps_stack *self, t_ps_stack *other_stack);
	int					(*compare_node)(t_ps_node_content *self_content, t_ps_node_content *content);
	void				(*destroy)(struct s_ps_stack	**self);
}	t_ps_stack;

typedef struct s_ps_node_content
{
	int				value;
	t_stack_node	*target_node;
}	t_ps_node_content;

t_ps_node_content	*new_ps_node_content(int number);
void				ps_stack_destroy(t_ps_stack	**self);
void 				ps_stack_update_on_transfer(t_ps_stack *self, t_ps_stack *other_stack);
int					compare_ps_node(t_ps_node_content *self_content, t_ps_node_content *content);

#endif
