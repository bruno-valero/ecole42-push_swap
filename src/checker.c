/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:06:16 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 19:00:04 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;
	char *str;
	str = malloc(11);
	read(0, str, 10);
	printf("buffer: %s", str);
	push_swap = new_push_swap();
	if (!push_swap->extract_input(push_swap, argc, argv))
	{
		write(2, "Error\n", 6);
		push_swap->destroy(&push_swap);
		return (1);
	}
	// push_swap->turk_sort->run(push_swap);
	push_swap->destroy(&push_swap);
	return (0);
}
