/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_closest_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:28:44 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 20:00:13 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	init_temps(t_find_closest_temps *temps, t_ps_stack *stack)
{
	temps->stack_length = stack->stack->length;
	temps->front_idx = 0;
	temps->back_idx = temps->stack_length - 1;
	temps->top = stack->stack->top;
	temps->bot = stack->stack->bottom;
}

int	is_bigger(t_stack_node *node_1, t_stack_node *node_2)
{
	return (contentof(node_1)->value > contentof(node_2)->value);
}

int	is_smaller(t_stack_node *node_1, t_stack_node *node_2)
{
	return (contentof(node_1)->value < contentof(node_2)->value);
}

void	continue_loop(t_find_closest_temps *temps)
{
	temps->top = temps->top->prev;
	temps->bot = temps->bot->next;
	temps->front_idx++;
	temps->back_idx--;
}

void	fill_get_closest_result(t_find_closest_temps *temps,
	t_find_closest_result *result, t_ps_stack *stack)
{
	if (valueof(temps->top) == stack->bigger)
		result->bigger_index = temps->front_idx;
	if (valueof(temps->bot) == stack->bigger)
		result->bigger_index = temps->back_idx;
	if (valueof(temps->top) == stack->smaller)
		result->smaller_index = temps->front_idx;
	if (valueof(temps->bot) == stack->smaller)
		result->smaller_index = temps->back_idx;
}
