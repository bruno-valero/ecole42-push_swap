/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_both.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:12:56 by valero            #+#    #+#             */
/*   Updated: 2025/08/21 18:25:15 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_push_swap *push_swap)
{
	return (swap_stack_both(push_swap));
}

int	rr(t_push_swap *push_swap)
{
	return (rotate_stack_both(push_swap));
}

int	rrr(t_push_swap *push_swap)
{
	return (rotate_reverse_stack_both(push_swap));
}
