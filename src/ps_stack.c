/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:57:15 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/20 13:24:16 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_node_content_destroy(t_ps_node_content	**node);

t_ps_stack	*new_ps_stack(int is_stack_a)
{
	t_ps_stack	*ps_stack;

	if (!is_stack_a)
		return (NULL);
	ps_stack = malloc(sizeof(t_ps_stack));
	ps_stack->is_stack_a = is_stack_a;
	ps_stack->bigger = 0;
	ps_stack->smaller = 0;
	ps_stack->stack = new_stack();
	ps_stack->destroy = ps_stack_destroy;
	return (ps_stack);
}

void	ps_stack_destroy(t_ps_stack	**self)
{
	(*self)->stack->destroy(&(*self)->stack, ps_node_content_destroy);
	free(*self);
	*self = NULL;
}

t_ps_node_content	*new_node_content(int number)
{
	t_ps_node_content	*node;

	node = malloc(sizeof(t_ps_node_content));
	node->value = number;
	node->target_node = NULL;
}

static void	ps_node_content_destroy(t_ps_node_content	**node)
{
	free(*node);
	*node = NULL;
}
