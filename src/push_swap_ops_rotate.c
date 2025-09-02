/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:13:07 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:01:57 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_push_swap *push_swap)
{
	return (rotate_stack(push_swap->stack_a));
}

int	rb(t_push_swap *push_swap)
{
	return (rotate_stack(push_swap->stack_b));
}

int	rra(t_push_swap *push_swap)
{
	return (rotate_reverse_stack(push_swap->stack_a));
}

int	rrb(t_push_swap *push_swap)
{
	return (rotate_reverse_stack(push_swap->stack_b));
}
