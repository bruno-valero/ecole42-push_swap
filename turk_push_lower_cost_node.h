/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_lower_cost_node.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:41:35 by valero            #+#    #+#             */
/*   Updated: 2025/08/30 18:42:19 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_PUSH_LOWER_COST_NODE_H
# define TURK_PUSH_LOWER_COST_NODE_H

typedef struct s_stack_node	t_stack_node;
typedef struct s_push_swap	t_push_swap;

void	turk_put_both_on_top(t_stack_node *node,
			t_push_swap *push_swap, int is_on_stack_a);
int		push_lower_cost_node(t_push_swap *push_swap, int is_pb);

#endif
