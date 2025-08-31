/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:26:58 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/30 19:37:55 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ts_stack	*new_ts_stack(t_ps_stack	*ps_stack);

t_turk_sort	*new_turk_sort(t_ps_stack	*ps_stack_a, t_ps_stack	*ps_stack_b)
{
	t_turk_sort	*turk_sort;

	if (!ps_stack_a || !ps_stack_b || !ps_stack_a->is_stack_a)
		return (NULL);
	turk_sort = malloc(sizeof(t_turk_sort));
	turk_sort->ts_stack_a = new_ts_stack(ps_stack_a);
	turk_sort->ts_stack_b = new_ts_stack(ps_stack_b);
	if (!turk_sort->ts_stack_a || !turk_sort->ts_stack_b)
	{
		turk_sort->ts_stack_a->destroy(&turk_sort->ts_stack_a);
		turk_sort->ts_stack_b->destroy(&turk_sort->ts_stack_b);
	}
	turk_sort->run = turk_run;
	turk_sort->destroy = turk_sort_destroy;
	return (turk_sort);
}

void	*turk_sort_destroy(t_turk_sort	**self_ref)
{
	if (!self_ref || !*self_ref)
		return (NULL);
	(*self_ref)->ts_stack_a->destroy(&(*self_ref)->ts_stack_a);
	(*self_ref)->ts_stack_b->destroy(&(*self_ref)->ts_stack_b);
	free(*self_ref);
	*self_ref = NULL;
	return (NULL);
}

static t_ts_stack	*new_ts_stack(t_ps_stack *ps_stack)
{
	t_ts_stack	*ts_stack;

	ts_stack = malloc(sizeof(t_ts_stack));
	ts_stack->median = 0;
	ts_stack->min_cost = 0;
	ts_stack->min_cost_index = 0;
	ts_stack->ps_stack = ps_stack;
	ts_stack->sort_three = turk_sort_three;
	ts_stack->destroy = ts_stack_destroy;
	return (ts_stack);
}

void	*ts_stack_destroy(t_ts_stack	**self_ref)
{
	if (!self_ref || !*self_ref)
		return (NULL);
	(*self_ref)->ps_stack->destroy(&(*self_ref)->ps_stack);
	free(*self_ref);
	*self_ref = NULL;
	return (NULL);
}
