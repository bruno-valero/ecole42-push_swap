/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_push_lower_cost_node.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:41:35 by valero            #+#    #+#             */
/*   Updated: 2025/09/01 15:56:35 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_PUSH_LOWER_COST_NODE_H
# define TURK_PUSH_LOWER_COST_NODE_H

typedef struct s_stack_node	t_stack_node;
typedef struct s_push_swap	t_push_swap;

void	turk_put_both_on_top(t_stack_node *node,
			t_push_swap *push_swap, int is_on_stack_a);
int		push_lower_cost_node(t_push_swap *push_swap, int is_pb);
void	put_thebothabove_on_top(t_stack_node *node, t_ps_stack *self_stack,
			t_ps_stack *other_stack, t_push_swap *push_swap);
void	put_thebothabelow_on_top(t_stack_node *node, t_ps_stack *self_stack,
			t_ps_stack *other_stack, t_push_swap *push_swap);
void	put_theaabove_on_top(t_stack_node *node, t_ps_stack *self_stack,
			t_ps_stack *other_stack);
void	put_theabelow_on_top(t_stack_node *node, t_ps_stack *self_stack,
			t_ps_stack *other_stack);
void	handle_alternative_push(t_stack_node *node, t_ps_stack *self_stack,
			t_ps_stack *other_stack, t_push_swap *push_swap);
int		turk_test_alternative_push(t_stack_node *node, int is_near_top);

#endif
