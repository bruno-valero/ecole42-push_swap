/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:54:42 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/03 16:31:31 by brunofer         ###   ########.fr       */
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
	node->target_index = 0;
	node->self_index = 0;
	node->target_node = NULL;
	node->push_cost = 0;
	node->self_stack_length = 0;
	node->other_stack_length = 0;
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
	return (s_cont->value == cont->value);
}

/**
 * # Retrieves the Typed Content of a Push Swap Node
 *
 * ---
 *
 * Provides access to the content stored in a `t_stack_node`, ensuring
 * it is returned as the correct type (`t_ps_node_content`).
 *
 * ---
 *
 * ## Why this function exists:
 *
 * - In a generic stack implementation, each node stores its data as a
 *   `void *` (generic pointer).
 * - While this allows flexibility, it requires explicit casting back
 *   to the correct type before use.
 * - This function centralizes and standardizes that casting, making the
 *   code cleaner and safer to maintain.
 *
 * ---
 *
 * ## How it works:
 *
 * 1. Takes a pointer to a `t_stack_node`.
 *
 * 2. Accesses the generic `content` field of the node.
 *
 * 3. Casts it into the specific type used in `push_swap`: `t_ps_node_content`.
 *
 * 4. Returns the correctly typed pointer.
 *
 * ---
 *
 * ## Benefits:
 *
 * - Removes repetitive casting throughout the codebase.
 * - Improves readability by making the programmer’s intent explicit.
 * - Reduces the chance of type-related mistakes when accessing node content.
 *
 * ---
 *
 * @param node  The stack node whose content will be accessed.
 *
 * ---
 *
 * @return A pointer to the `t_ps_node_content` stored in the given node.
 */
t_ps_node_content	*contentof(t_stack_node *node)
{
	if (!node)
		return (NULL);
	return ((t_ps_node_content *)node->content);
}

int	valueof(t_stack_node *node)
{
	if (!node)
		return (0);
	return (contentof(node)->value);
}
