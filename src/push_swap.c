/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:22:05 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/19 16:23:36 by brunofer         ###   ########.fr       */
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
	push_swap->destroy = push_swap_destroy;
}

void	push_swap_destroy(
		t_push_swap	**self, void (*del_content_node)(void *content))
{
	(*self)->stack_a->destroy(&(*self)->stack_a, del_content_node);
	(*self)->stack_b->destroy(&(*self)->stack_b, del_content_node);
	(*self)->ops->destroy(&(*self)->ops);
	free(*self);
	*self = NULL;
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
