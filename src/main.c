/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:06:16 by valero            #+#    #+#             */
/*   Updated: 2025/08/21 11:46:08 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_ps_node_content	*current_content;
	t_stack_node		*temp_node;

	temp_node = stack->top;
	printf("[ ");
	while (temp_node)
	{
		current_content = (t_ps_node_content *)temp_node->content;
		printf("%d, ", current_content->value);
		temp_node = temp_node->prev;
	}
	printf("]");
}

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	push_swap = new_push_swap();
	push_swap->extract_input(push_swap, argc, argv);
	print_stack(push_swap->stack_a->stack);
	return (0);
}
