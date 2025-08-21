/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:22:05 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/21 18:41:02 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_push_swap_ops	*new_push_swap_ops(void);

t_push_swap	*new_push_swap(void)
{
	t_push_swap	*push_swap;
	t_ps_stack	*stack_a;
	t_ps_stack	*stack_b;

	stack_a = new_ps_stack(1);
	stack_b = new_ps_stack(0);
	push_swap = malloc(sizeof(t_push_swap));
	if (!push_swap)
	{
		destroy_ps_stacks(stack_a, stack_b);
		return (NULL);
	}
	push_swap->stack_a = stack_a;
	push_swap->stack_b = stack_b;
	push_swap->ops = new_push_swap_ops();
	push_swap->fill_stack_a = fill_stack_a;
	push_swap->extract_input = extract_input;
	push_swap->destroy = push_swap_destroy;
	return (push_swap);
}

void	push_swap_destroy(t_push_swap	**self)
{
	(*self)->stack_a->destroy(&(*self)->stack_a);
	(*self)->stack_b->destroy(&(*self)->stack_b);
	(*self)->ops->destroy(&(*self)->ops);
	free(*self);
	*self = NULL;
}

int	fill_stack_a(t_push_swap *self, int number)
{
	t_ps_node_content	*content;
	t_stack_node		*new_node;

	if (!self || !self->stack_a || !self->stack_a->stack)
		return (0);
	if (!self->stack_a->stack->length)
	{
		self->stack_a->bigger = INT_MIN;
		self->stack_a->smaller = INT_MAX;
	}
	content = new_ps_node_content(number);
	if (self->stack_a->bigger < number)
		self->stack_a->bigger = number;
	if (self->stack_a->smaller > number)
		self->stack_a->smaller = number;
	new_node = self->stack_a->stack->create_node(content);
	if (!self->stack_a->stack->push_unique(
			self->stack_a->stack, new_node, self->stack_a->compare_node))
	{
		ps_node_content_destroy(&new_node);
		return (0);
	}
	return (1);
}

static t_push_swap_ops	*new_push_swap_ops(void)
{
	t_push_swap_ops	*ps_ops;

	ps_ops = malloc(sizeof(t_push_swap_ops));
	if (!ps_ops)
		return (NULL);
	ps_ops->sa = sa;
	ps_ops->sb = sb;
	ps_ops->ss = ss;
	ps_ops->pa = pa;
	ps_ops->pb = pb;
	ps_ops->ra = ra;
	ps_ops->rb = rb;
	ps_ops->rr = rr;
	ps_ops->rra = rra;
	ps_ops->rrb = rrb;
	ps_ops->rrr = rrr;
	ps_ops->destroy = push_swap_ops_destroy;
	return (ps_ops);
}

void	push_swap_ops_destroy(t_push_swap_ops	**self)
{
	if (!self || !*self)
		return ;
	free(*self);
	*self = NULL;
}
