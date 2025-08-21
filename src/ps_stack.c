/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:57:15 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/21 00:18:02 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_node_content_destroy(t_ps_node_content	**node);

t_ps_stack	*new_ps_stack(int is_stack_a)
{
	t_ps_stack	*ps_stack;

	ps_stack = malloc(sizeof(t_ps_stack));
	if (!is_stack_a || !ps_stack)
		return (NULL);
	ps_stack->is_stack_a = is_stack_a;
	ps_stack->bigger = 0;
	ps_stack->smaller = 0;
	ps_stack->stack = new_stack();
	ps_stack->update_on_transfer = ps_stack_update_on_transfer;
	ps_stack->compare_node = compare_ps_node;
	ps_stack->destroy = ps_stack_destroy;
	return (ps_stack);
}

void	ps_stack_destroy(t_ps_stack	**self)
{
	if (!self || !*self || !(*self)->stack)
		return (NULL);
	(*self)->stack->destroy(&(*self)->stack, ps_node_content_destroy);
	free(*self);
	*self = NULL;
}

t_ps_node_content	*new_ps_node_content(int number)
{
	t_ps_node_content	*node;

	node = malloc(sizeof(t_ps_node_content));
	if (!node)
		return (NULL);
	node->value = number;
	node->target_node = NULL;
}

int	compare_ps_node(t_ps_node_content *self_content, t_ps_node_content *content)
{
	return (self_content->value == content->value);
}

static void	ps_node_content_destroy(t_ps_node_content	**node)
{
	free(*node);
	*node = NULL;
}
