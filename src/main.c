/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:06:16 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/03 21:38:14 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_ps_stack *stack)
{
	t_ps_node_content	*current_content;
	t_stack_node		*temp_node;

	temp_node = stack->stack->top;
	if (stack->is_stack_a)
		printf("stack_a: ");
	else
		printf("stack_b: ");
	printf("[ ");
	while (temp_node)
	{
		current_content = (t_ps_node_content *)temp_node->content;
		printf("%d, ", current_content->value);
		temp_node = temp_node->prev;
	}
	printf("]\n");
}

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (argc == 1)
		return (0);
	push_swap = new_push_swap(1);
	if (!push_swap->extract_input(push_swap, argc, argv))
	{
		write(2, "Error\n", 6);
		push_swap->destroy(&push_swap);
		return (1);
	}
	push_swap->turk_sort->run(push_swap);
	push_swap->destroy(&push_swap);
	return (0);
}
