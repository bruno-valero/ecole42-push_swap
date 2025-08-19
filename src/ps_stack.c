/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:57:15 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/19 15:57:39 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_stack	*new_ps_stack(int is_stack_a)
{
	t_ps_stack	*ps_stack;

	if (!is_stack_a)
		return (NULL);
	ps_stack = malloc(sizeof(t_ps_stack));
	ps_stack->is_stack_a = is_stack_a;
	ps_stack->stack = new_stack();
	ps_stack->destroy = ps_stack_destroy;
	return (ps_stack);
}

void	ps_stack_destroy(
		t_ps_stack	**self, void (*del_node_content)(void *content))
{
	(*self)->stack->destroy(&(*self)->stack, del_node_content);
	free(*self);
	*self = NULL;
}
