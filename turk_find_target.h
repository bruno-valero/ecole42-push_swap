/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_target.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:50:51 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 16:52:26 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_FIND_TARGET_H
# define TURK_FIND_TARGET_H

typedef struct s_stack_node	t_stack_node;
typedef struct s_ts_stack	t_ts_stack;

t_stack_node	*find_target_node(t_stack_node *node, t_ts_stack *ts_stack);

#endif
