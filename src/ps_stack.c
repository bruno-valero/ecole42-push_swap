/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:57:15 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/03 14:14:51 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_stack	*new_ps_stack(int is_stack_a, int print_moves)
{
	t_ps_stack	*ps_stack;

	ps_stack = malloc(sizeof(t_ps_stack));
	if (!ps_stack)
		return (NULL);
	ps_stack->is_stack_a = is_stack_a;
	ps_stack->print_moves = print_moves;
	ps_stack->bigger = 0;
	ps_stack->smaller = 0;
	ps_stack->stack = new_stack();
	ps_stack->update_on_transfer = ps_stack_update_on_transfer;
	ps_stack->compare_node = compare_ps_node;
	ps_stack->get_content = contentof;
	ps_stack->destroy = ps_stack_destroy;
	return (ps_stack);
}

void	ps_stack_destroy(t_ps_stack	**self)
{
	if (!self || !*self || !(*self)->stack)
		return ;
	(*self)->stack->destroy(&(*self)->stack, ps_node_content_destroy);
	free(*self);
	*self = NULL;
}

void	*destroy_ps_stacks(t_ps_stack **stack_a, t_ps_stack **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->stack)
		(*stack_a)->destroy(stack_a);
	if (stack_a && *stack_b && (*stack_b)->stack)
		(*stack_b)->destroy(stack_b);
	return (NULL);
}
