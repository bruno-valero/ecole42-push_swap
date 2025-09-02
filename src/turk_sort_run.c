/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:34:20 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:01:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_sort(t_push_swap *push_swap);
static int	is_ordered(t_stack *stack_a);

void	turk_run(t_push_swap *push_swap)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = push_swap->stack_a->stack;
	stack_b = push_swap->stack_b->stack;
	if (is_ordered(stack_a))
		return ;
	if (stack_a->length == 1)
		return ;
	if (stack_a->length == 2)
	{
		turk_sort_two(push_swap->turk_sort->ts_stack_a, push_swap);
		return ;
	}
	while (stack_a->length > 3)
		push_lower_cost_node(push_swap, 1);
	turk_sort_three(push_swap->turk_sort->ts_stack_a, push_swap);
	while (stack_b->length)
		push_lower_cost_node(push_swap, 0);
	// printf("is_ordered: %d\n", is_ordered(push_swap->stack_a->stack));
	final_sort(push_swap);
	// printf("is_ordered: %d\n", is_ordered(push_swap->stack_a->stack));
}

static void	final_sort(t_push_swap *push_swap)
{
	t_stack			*stack_a;
	t_stack_node	*top;
	unsigned int	unsorted_count;

	stack_a = push_swap->stack_a->stack;
	top = stack_a->top;
	unsorted_count = 0;
	while (valueof(top) > valueof(stack_a->bottom))
	{
		top = top->prev;
		unsorted_count++;
	}
	if (unsorted_count <= (stack_a->length / 2))
		while (valueof(stack_a->top) > valueof(stack_a->bottom))
			push_swap->ops->ra(push_swap);
	if (unsorted_count > (stack_a->length / 2))
		while (valueof(stack_a->top) > valueof(stack_a->bottom))
			push_swap->ops->rra(push_swap);
}

static int	is_ordered(t_stack *stack_a)
{
	t_stack_node	*top;
	t_stack_node	*bot;
	unsigned int	idx;

	idx = 0;
	top = stack_a->top;
	bot = stack_a->bottom;
	while (idx++ <= stack_a->length / 2)
	{
		if (top && valueof(top) > valueof(top->prev))
			return (0);
		if (bot && valueof(bot) < valueof(bot->next))
			return (0);
		top = top->prev;
		bot = bot->next;
	}
	return (1);
}
