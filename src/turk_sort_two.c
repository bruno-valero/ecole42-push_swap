/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:12:11 by valero            #+#    #+#             */
/*   Updated: 2025/08/30 19:17:02 by valero           ###   ########.fr       */
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
