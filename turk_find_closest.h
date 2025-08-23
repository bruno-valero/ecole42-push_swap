/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_closest.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:15:33 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/23 17:46:24 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TURK_FIND_CLOSEST_H
# define TURK_FIND_CLOSEST_H

typedef struct s_stack_node				t_stack_node;
typedef struct s_find_closest_result	t_find_closest_result;

struct s_find_closest_result
{
	int				index;
	t_stack_node	*value;
};

t_find_closest_result	turk_find_closest_bigger(
							t_stack_node *node, t_ps_stack *other_stack);
t_find_closest_result	turk_find_closest_smaller(
							t_stack_node *node, t_ps_stack *other_stack);

#endif
