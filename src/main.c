/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:06:16 by valero            #+#    #+#             */
/*   Updated: 2025/08/23 18:04:25 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_ps_stack  *stack)
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

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	push_swap = new_push_swap();
	if (!push_swap->extract_input(push_swap, argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_stack(push_swap->stack_a);
	push_swap->ops->pb(push_swap);
	push_swap->ops->pb(push_swap);
	push_swap->ops->pb(push_swap);
	push_swap->ops->pb(push_swap);
	print_stack(push_swap->stack_a);
	print_stack(push_swap->stack_b);
	printf("closest bigger: %d\n", get_ps_content(turk_find_closest_bigger(push_swap->stack_a->stack->top, push_swap->stack_b).value)->value);
	return (0);
}

// 1 5 9 7 4 8 2 0
