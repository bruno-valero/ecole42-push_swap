/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:13:07 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:04:48 by brunofer         ###   ########.fr       */
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
