/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_lower_cost.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:47:00 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 18:57:59 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_FIND_LOWER_COST_H
# define TURK_FIND_LOWER_COST_H

typedef struct s_ts_stack	t_ts_stack;

t_stack_node	*find_lower_cost(t_push_swap *push_swap, int is_on_stack_a);

#endif
