/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_lower_cost_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:39:05 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/01 16:48:16 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	turk_get_cost(t_stack_node *node, int is_self, int is_near_top);
static int	turk_get_alt_cost(t_stack_node *node, int is_self, int its_cost);
static int	turk_greater(int nbr1, int nbr2);

void	handle_alternative_push(t_stack_node *node, t_ps_stack *self_stack,
			t_ps_stack *other_stack, t_push_swap *push_swap)
{
	int	alternative_push;

	if (is_above_center(node))
	{
		alternative_push = turk_test_alternative_push(node, 1);
		if (alternative_push == 1)
			return (put_thebothabove_on_top(node, self_stack,
					other_stack, push_swap));
		if (alternative_push == -1)
			return (put_thebothabelow_on_top(node, self_stack,
					other_stack, push_swap));
		return (put_theaabove_on_top(node, self_stack, other_stack));
	}
	alternative_push = turk_test_alternative_push(node, 0);
	if (alternative_push == 1)
		return (put_thebothabove_on_top(node, self_stack,
				other_stack, push_swap));
	if (alternative_push == -1)
		return (put_thebothabelow_on_top(node, self_stack,
				other_stack, push_swap));
	return (put_theabelow_on_top(node, self_stack, other_stack));
}

int	turk_test_alternative_push(t_stack_node *node, int is_near_top)
{
	int	self_cost;
	int	self_alt_cost;
	int	target_cost;
	int	target_alt_cost;

	self_cost = turk_get_cost(node, 1, is_near_top);
	self_alt_cost = turk_get_alt_cost(node, 1, self_cost);
	target_cost = turk_get_cost(node, 0, is_near_top);
	target_alt_cost = turk_get_alt_cost(node, 0, target_cost);
	if (turk_greater(self_alt_cost, target_cost) <= self_cost + target_cost)
	{
		if (is_near_top)
			return (-1);
		return (1);
	}
	if (turk_greater(target_alt_cost, self_cost) <= self_cost + target_cost)
	{
		if (is_near_top)
			return (1);
		return (-1);
	}
	return (0);
}

static int	turk_get_cost(t_stack_node *node, int is_self, int is_near_top)
{
	if (is_near_top)
	{
		if (is_self)
			return (contentof(node)->self_index);
		return (contentof(node)->other_stack_length
			- contentof(node)->target_index);
	}
	if (is_self)
		return (contentof(node)->self_stack_length
			- contentof(node)->self_index);
	return (contentof(node)->target_index);
}

static int	turk_get_alt_cost(t_stack_node *node, int is_self, int its_cost)
{
	if (is_self)
		return (contentof(node)->self_stack_length - its_cost);
	return (contentof(node)->other_stack_length - its_cost);
}

static int	turk_greater(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}
