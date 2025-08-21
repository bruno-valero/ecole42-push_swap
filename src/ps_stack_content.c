/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:54:42 by valero            #+#    #+#             */
/*   Updated: 2025/08/21 17:04:49 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_node_content	*new_ps_node_content(int number)
{
	t_ps_node_content	*node;

	node = malloc(sizeof(t_ps_node_content));
	if (!node)
		return (NULL);
	node->value = number;
	node->target_node = NULL;
	return (node);
}

void	ps_node_content_destroy(void *node)
{
	t_ps_node_content	**ps_node_content;

	ps_node_content = (t_ps_node_content **)node;
	free(*ps_node_content);
	*ps_node_content = NULL;
}

int	compare_ps_node(void *self_content, void *content)
{
	t_ps_node_content	*s_cont;
	t_ps_node_content	*cont;

	s_cont = (t_ps_node_content *)self_content;
	cont = (t_ps_node_content *)content;
	return (s_cont->value == (cont)->value);
}
