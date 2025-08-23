/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:12:34 by valero            #+#    #+#             */
/*   Updated: 2025/08/22 23:02:59 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_SORT_H
# define TURK_SORT_H

typedef struct s_ps_stack	t_ps_stack;

typedef struct s_turk_sort	t_turk_sort;
typedef struct s_ts_stach	t_ts_stach;

struct s_turk_sort
{
	t_ts_stach	*ts_stack_a;
	t_ts_stach	*ts_stack_b;
};

struct s_ts_stach
{
	int			min_cost;
	int			min_cost_index;
	int			median;
	void		(*sort_three)(t_ts_stach *self);
	void		(*find_target)(t_ts_stach *self, t_ts_stach *other);
	void		(*push)(t_ts_stach *self, t_ts_stach *other);
	t_ps_stack	*ps_stack;
};

#endif
