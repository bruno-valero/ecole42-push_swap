/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:06:16 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/04 17:39:48 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (argc == 1)
		return (0);
	push_swap = new_push_swap(1);
	if (!push_swap->extract_input(push_swap, argc, argv))
	{
		write(2, "Error\n", 6);
		push_swap->destroy(&push_swap);
		return (1);
	}
	push_swap->turk_sort->run(push_swap);
	push_swap->destroy(&push_swap);
	return (0);
}
