/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_by_index.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:44:27 by valero            #+#    #+#             */
/*   Updated: 2025/08/24 22:46:52 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_FIND_BY_INDEX_H
# define TURK_FIND_BY_INDEX_H

typedef struct s_stack_node	t_stack_node;
typedef struct s_stack		t_stack;

t_stack_node	*find_by_index(int index, t_stack stack);

#endif
