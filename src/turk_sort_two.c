/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:12:11 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:01:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	turk_sort_two(t_ts_stack *self, t_push_swap *push_swap)
{
	t_stack	*stack;

	stack = self->ps_stack->stack;
	if (stack->length != 2)
		return (0);
	if (valueof(stack->top) > valueof(stack->bottom))
		push_swap->ops->sa(push_swap);
	return (1);
}
