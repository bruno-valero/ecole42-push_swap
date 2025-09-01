/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:12:34 by valero            #+#    #+#             */
/*   Updated: 2025/08/31 12:30:51 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_SORT_H
# define TURK_SORT_H

# include "turk_find_closest.h"
# include "turk_find_target.h"
# include "turk_calculate_cost.h"
# include "turk_find_lower_cost.h"
# include "turk_find_by_index.h"
# include "turk_push_lower_cost_node.h"

typedef struct s_ps_stack	t_ps_stack;

typedef struct s_turk_sort	t_turk_sort;
typedef struct s_ts_stack	t_ts_stack;

struct s_turk_sort
{
	t_ts_stack	*ts_stack_a;
	t_ts_stack	*ts_stack_b;
	void		(*run)(t_push_swap *push_swap);
	void		*(*destroy)(t_turk_sort	**self_ref);
};

struct s_ts_stack
{
	int			min_cost;
	int			min_cost_index;
	int			median;
	int			(*sort_three)(t_ts_stack *self, t_push_swap *push_swap);
	void		(*push)(t_ts_stack *self, t_ts_stack *other);
	void		*(*destroy)(t_ts_stack	**self_ref);
	t_ps_stack	*ps_stack;
};

t_turk_sort	*new_turk_sort(t_ps_stack	*ps_stack_a, t_ps_stack	*ps_stack_b);
void		*turk_sort_destroy(t_turk_sort	**self_ref);
void		*ts_stack_destroy(t_ts_stack	**self_ref);

int			turk_sort_three(t_ts_stack *self, t_push_swap *push_swap);
int			turk_sort_two(t_ts_stack *self, t_push_swap *push_swap);
void		turk_run(t_push_swap *push_swap);

#endif
