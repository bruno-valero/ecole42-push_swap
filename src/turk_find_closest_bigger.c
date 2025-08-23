/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_closest_bigger.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:10:27 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/23 19:32:19 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps_node_content	make_content(int value);

t_find_closest_result	turk_find_closest_bigger(
	t_stack_node *node, t_ps_stack *other_stack)
{
	t_find_closest_result	result;
	t_stack_node			*current_node;
	t_stack_node			*closest_bigger;
	int						index;

	index = 0;
	current_node = other_stack->stack->top;
	closest_bigger = current_node;
	while (current_node)
	{
		if (get_ps_content(current_node)->value
			> get_ps_content(node)->value
			&& get_ps_content(current_node)->value
			< get_ps_content(closest_bigger)->value)
			closest_bigger = current_node;
		current_node = current_node->prev;
		index++;
	}
	result.index = index;
	result.value = closest_bigger;
	return (result);
}

static t_ps_node_content	make_content(int value)
{
	t_ps_node_content	content;

	content.value = value;
	content.target_node = NULL;
	return (content);
}

