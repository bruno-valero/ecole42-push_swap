/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_closest_smaller.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:10:27 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/23 16:39:12 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_find_closest_result	turk_find_closest_smaller(
	t_stack_node *node, t_ps_stack *other_stack)
{
	t_find_closest_result	result;
	t_stack_node			*current_node;
	t_stack_node			*closest_smaller;
	int						index;

	index = 0;
	current_node = other_stack->stack->top;
	closest_smaller = current_node;
	while (current_node)
	{
		if (get_ps_content(current_node)->value
			< get_ps_content(node)->value
			&& get_ps_content(current_node)->value
			> get_ps_content(closest_smaller)->value)
			closest_smaller = current_node;
		current_node = current_node->prev;
		index++;
	}
	result.index = index;
	result.value = closest_smaller;
	return (result);
}
