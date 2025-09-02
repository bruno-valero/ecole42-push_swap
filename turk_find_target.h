/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_target.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:50:51 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 18:58:03 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_FIND_TARGET_H
# define TURK_FIND_TARGET_H

typedef struct s_stack_node	t_stack_node;
typedef struct s_ts_stack	t_ts_stack;

int	turk_find_stack_targets(t_push_swap *push_swap, int is_on_stack_a);

#endif
