/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:06:16 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/03 14:28:01 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	response_error(t_push_swap *push_swap);
static int	response_ok(t_push_swap *push_swap);
static void	make_ops(char *str, t_push_swap *push_swap);

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;
	char		*str;

	push_swap = new_push_swap(0);
	str = get_next_line(0);
	if (!push_swap->extract_input(push_swap, argc, argv))
	{
		if (!ft_strncmp(str, "Error\n", 7))
			return (response_ok(push_swap));
		return (response_error(push_swap));
	}
	while (str)
	{
		make_ops(str, push_swap);
		free(str);
		str = get_next_line(0);
	}
	if (is_ordered(push_swap->stack_a->stack))
		return (response_ok(push_swap));
	return (response_error(push_swap));
}

static void	make_ops(char *str, t_push_swap *push_swap)
{
	if (!ft_strncmp(str, "sa\n", 3))
		push_swap->ops->sa(push_swap);
	if (!ft_strncmp(str, "sb\n", 3))
		push_swap->ops->sb(push_swap);
	if (!ft_strncmp(str, "ss\n", 3))
		push_swap->ops->ss(push_swap);
	if (!ft_strncmp(str, "pa\n", 3))
		push_swap->ops->pa(push_swap);
	if (!ft_strncmp(str, "pb\n", 3))
		push_swap->ops->pb(push_swap);
	if (!ft_strncmp(str, "ra\n", 3))
		push_swap->ops->ra(push_swap);
	if (!ft_strncmp(str, "rb\n", 3))
		push_swap->ops->rb(push_swap);
	if (!ft_strncmp(str, "rr\n", 3))
		push_swap->ops->rr(push_swap);
	if (!ft_strncmp(str, "rra\n", 4))
		push_swap->ops->rra(push_swap);
	if (!ft_strncmp(str, "rrb\n", 4))
		push_swap->ops->rrb(push_swap);
	if (!ft_strncmp(str, "rrr\n", 4))
		push_swap->ops->rrr(push_swap);
}

static int	response_error(t_push_swap *push_swap)
{
	write(2, "KO\n", 6);
	push_swap->destroy(&push_swap);
	return (1);
}

static int	response_ok(t_push_swap *push_swap)
{
	write(2, "OK\n", 3);
	push_swap->destroy(&push_swap);
	return (0);
}
