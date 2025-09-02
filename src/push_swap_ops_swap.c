/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:13:12 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:01:57 by brunofer         ###   ########.fr       */
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
