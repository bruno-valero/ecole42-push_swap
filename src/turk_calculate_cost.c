/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_calculate_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:29:01 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 21:14:36 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	costof_both_above(int *push_cost, int self_index, int target_index);
static void	costof_both_below(t_stack_node *node, int *push_cost,
				int self_index, int target_index);
static void	costof_self_above(t_stack_node *node, int *push_cost,
				int self_index, int target_index);
static void	costof_self_below(t_stack_node *node, int *push_cost,
				int self_index, int target_index);

void	calculate_push_cost(t_stack_node *node)
{
	int	push_cost;
	int	self_index;
	int	target_index;

	push_cost = 0;
	self_index = contentof(node)->self_index;
	target_index = contentof(node)->target_index;
	if (is_both_above_center(node))
		costof_both_above(&push_cost, self_index, target_index);
	else if (is_both_below_center(node))
		costof_both_below(node, &push_cost, self_index, target_index);
	else if (is_above_center(node))
		costof_self_above(node, &push_cost, self_index, target_index);
	else
		costof_self_below(node, &push_cost, self_index, target_index);
	contentof(node)->push_cost = push_cost;
}

static void	costof_both_above(int *push_cost, int self_index, int target_index)
{
	while (self_index-- && target_index--)
		(*push_cost)++;
	while (self_index || target_index)
	{
		if (self_index)
			self_index--;
		if (target_index)
			target_index--;
		(*push_cost)++;
	}
}

static void	costof_both_below(t_stack_node *node, int *push_cost,
	int self_index, int target_index)
{
	while (self_index++ < contentof(node)->self_stack_length
		&& target_index++ < contentof(node)->other_stack_length)
		(*push_cost)++;
	while (self_index < contentof(node)->self_stack_length
		|| target_index < contentof(node)->other_stack_length)
	{
		if (self_index < contentof(node)->self_stack_length)
			self_index++;
		if (target_index < contentof(node)->other_stack_length)
			target_index++;
		(*push_cost)++;
	}
	(*push_cost)++;
}

static void	costof_self_above(t_stack_node *node, int *push_cost,
	int self_index, int target_index)
{
	while (self_index || target_index < contentof(node)->other_stack_length)
	{
		if (self_index)
		{
			self_index--;
			(*push_cost)++;
		}
		if (target_index < contentof(node)->other_stack_length)
		{
			target_index++;
			(*push_cost)++;
		}
	}
	(*push_cost)++;
}

static void	costof_self_below(t_stack_node *node, int *push_cost,
	int self_index, int target_index)
{
	while (self_index < contentof(node)->self_stack_length || target_index)
	{
		if (self_index < contentof(node)->self_stack_length)
		{
			self_index++;
			(*push_cost)++;
		}
		if (target_index)
		{
			target_index--;
			(*push_cost)++;
		}
	}
	(*push_cost)++;
}
