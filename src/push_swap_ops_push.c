/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:13:07 by valero            #+#    #+#             */
/*   Updated: 2025/08/22 23:06:05 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_push_swap *push_swap)
{
	return (push_stack1_to_stack2(push_swap, 0));
}

int	pb(t_push_swap *push_swap)
{
	return (push_stack1_to_stack2(push_swap, 1));
}
