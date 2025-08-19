/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:03:32 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/19 12:06:54 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	int number = 8;
	t_stack	*stack = new_stack();
	stack->push(stack, stack->create_node(&number));
	printf("bottom_ref = %p, top_ref = %p, length = %d, top_value = %d\n", stack->bottom, stack->top, stack->length, *(int *)stack->top->content);
}
