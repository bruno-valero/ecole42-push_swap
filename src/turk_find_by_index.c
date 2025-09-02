/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_by_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:28:02 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:01:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_index_above_center(int index, t_stack *stack);

t_stack_node	*find_by_index(int index, t_stack *stack)
{
	int				curr_index;
	t_stack_node	*top;
	t_stack_node	*bot;

	top = stack->top;
	bot = stack->bottom;
	if (is_index_above_center(index, stack))
		curr_index = 0;
	else
		curr_index = stack->length - 1;
	while ((unsigned int)curr_index != stack->length / 2)
	{
		if (curr_index == index)
			break ;
		if (is_index_above_center(index, stack))
			curr_index++;
		else
			curr_index--;
		top = top->prev;
		bot = bot->next;
	}
	if (is_index_above_center(index, stack))
		return (top);
	return (bot);
}

static int	is_index_above_center(int index, t_stack *stack)
{
	return ((unsigned int)index < stack->length / 2);
}
