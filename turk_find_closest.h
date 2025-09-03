/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_closest.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:15:33 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/03 14:32:36 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_FIND_CLOSEST_H
# define TURK_FIND_CLOSEST_H

typedef struct s_stack_node				t_stack_node;

typedef struct s_find_closest_result	t_find_closest_result;
typedef struct s_find_closest_temps		t_find_closest_temps;

struct s_find_closest_result
{
	int				index;
	int				succeed;
	int				bigger_index;
	int				smaller_index;
	t_stack_node	*value;
};

struct s_find_closest_temps
{
	int				front_idx;
	int				back_idx;
	int				back;
	int				stack_length;
	t_stack_node	*top;
	t_stack_node	*bot;
};

t_find_closest_result	turk_find_closest_bigger(t_stack_node *node,
							t_ps_stack *stack, t_stack_node *temp_node);
t_find_closest_result	turk_find_closest_smaller(t_stack_node *node,
							t_ps_stack *stack, t_stack_node *temp_node);
int						is_bigger(t_stack_node *node_1, t_stack_node *node_2);
int						is_smaller(t_stack_node *node_1, t_stack_node *node_2);
void					init_temps(t_find_closest_temps *temps,
							t_ps_stack *stack);
void					fill_get_closest_result(t_find_closest_temps *temps,
							t_find_closest_result *result, t_ps_stack *stack);
void					continue_loop(t_find_closest_temps *temps);
void					turk_change_closest(t_stack_node *curr_node,
							t_find_closest_temps *temps,
							t_find_closest_result *result);

#endif
