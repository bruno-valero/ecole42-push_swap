/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:06:16 by valero            #+#    #+#             */
/*   Updated: 2025/08/30 19:38:26 by valero           ###   ########.fr       */
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
	t_find_closest_result result;
	result = turk_find_closest_bigger(push_swap->stack_a->stack->top, push_swap->stack_b, NULL);
	if (result.succeed)
		printf("closest bigger from %d: %d\n", contentof(push_swap->stack_a->stack->top)->value, contentof(result.value)->value);
	else
		printf("closest bigger not found!");
	result = turk_find_closest_smaller(push_swap->stack_a->stack->top, push_swap->stack_b, NULL);
	if (result.succeed)
		printf("closest smaller from %d: %d\n", contentof(push_swap->stack_a->stack->top)->value, contentof(result.value)->value);
	else
		printf("closest smaller not found!");
	return (0);
}

// 1 5 9 7 4 8 2 0
