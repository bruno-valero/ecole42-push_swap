/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:03:32 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/21 11:50:21 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int		number;
	t_stack	*stack;

	number = 8;
	stack = new_stack();
	stack->push(stack, stack->create_node(&number));
	printf("bottom_ref = %p, top_ref = %p, length = %d, top_value = %d\n",
		stack->bottom, stack->top, stack->length, *(int *)stack->top->content);
}
