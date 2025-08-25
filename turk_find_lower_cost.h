/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_lower_cost.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:47:00 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 21:48:41 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_FIND_LOWER_COST_H
# define TURK_FIND_LOWER_COST_H

typedef struct s_stack_node				t_stack_node;
typedef struct s_ts_stack				t_ts_stack;

t_stack_node	*find_lower_cost(t_ts_stack	*ts_stack);

#endif
