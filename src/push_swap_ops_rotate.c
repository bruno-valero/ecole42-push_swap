/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:13:07 by valero            #+#    #+#             */
/*   Updated: 2025/08/21 18:24:33 by valero           ###   ########.fr       */
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
