/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:22:05 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/20 22:27:08 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*new_push_swap(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	push_swap->stack_a = stack_a;
	push_swap->stack_b = stack_b;
	push_swap->ops = new_push_swap_ops();
	push_swap->fill_stack_a = fill_stack_a;
	push_swap->destroy = push_swap_destroy;
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
	t_stack_node *new_node;

	if (!self || !self->stack_a || !self->stack_a->stack)
		return (0);
	content = new_ps_node_content(number);
	if (self->stack_a->bigger < number)
		self->stack_a->bigger = number;
	if (self->stack_a->smaller > number)
		self->stack_a->smaller = number;
	new_node = self->stack_a->stack->create_node(content);
	if (!self->stack_a->stack->push_unique(self->stack_a->stack, new_node, self->stack_a->compare_node))
		return (0);
}

t_push_swap_ops	*new_push_swap_ops(void)
{
	t_push_swap_ops	*ps_ops;

	ps_ops = malloc(sizeof(t_push_swap_ops));
	ps_ops->rotate = rotate_stack;
	ps_ops->rotate_both = rotate_stack_both;
	ps_ops->rotate_reverse = rotate_reverse_stack;
	ps_ops->rotate_reverse_both = rotate_reverse_stack_both;
	ps_ops->stack1_push_to_stack2 = stack1_push_to_stack2;
	ps_ops->swap = swap_stack;
	ps_ops->swap_both = swap_stack_both;
	ps_ops->destroy = push_swap_ops_destroy;
}

void	push_swap_ops_destroy(t_push_swap_ops	**self)
{
	free(*self);
	*self = NULL;
}
