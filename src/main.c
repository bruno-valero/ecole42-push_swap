/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:06:16 by valero            #+#    #+#             */
/*   Updated: 2025/08/21 15:31:06 by valero           ###   ########.fr       */
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

	push_swap = new_push_swap();
	if (!push_swap->extract_input(push_swap, argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_stack(push_swap->stack_a);
	push_swap->ops->rotate_reverse(push_swap->stack_a);
	push_swap->ops->push_stack1_to_stack2(push_swap, 1);
	push_swap->ops->push_stack1_to_stack2(push_swap, 1);
	push_swap->ops->rotate_reverse(push_swap->stack_a);
	push_swap->ops->push_stack1_to_stack2(push_swap, 1);
	push_swap->ops->push_stack1_to_stack2(push_swap, 1);
	print_stack(push_swap->stack_a);
	print_stack(push_swap->stack_b);
	push_swap->ops->rotate(push_swap->stack_b);
	push_swap->ops->rotate(push_swap->stack_b);
	push_swap->ops->rotate_reverse(push_swap->stack_b);
	print_stack(push_swap->stack_a);
	print_stack(push_swap->stack_b);
	printf("stack_a.bigger: %d, stack_a.smaller: %d\n", push_swap->stack_a->bigger, push_swap->stack_a->smaller);
	printf("stack_b.bigger: %d, stack_b.smaller: %d\n", push_swap->stack_b->bigger, push_swap->stack_b->smaller);
	push_swap->ops->push_stack1_to_stack2(push_swap, 0);
	print_stack(push_swap->stack_a);
	print_stack(push_swap->stack_b);
	return (0);
}
