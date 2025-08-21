/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:13:12 by valero            #+#    #+#             */
/*   Updated: 2025/08/21 18:17:52 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_push_swap *push_swap)
{
	return (swap_stack(push_swap->stack_a));
}

int	sb(t_push_swap *push_swap)
{
	return (swap_stack(push_swap->stack_b));
}
