/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:27:03 by valero            #+#    #+#             */
/*   Updated: 2025/08/21 18:42:12 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_OPS_H
# define PUSH_SWAP_OPS_H

typedef struct s_push_swap		t_push_swap;
typedef struct s_push_swap_ops	t_push_swap_ops;
typedef struct s_ps_stack		t_ps_stack;

struct s_push_swap_ops
{
	int			(*sa)(t_push_swap *push_swap);
	int			(*sb)(t_push_swap *push_swap);
	int			(*ss)(t_push_swap *push_swap);
	int			(*pa)(t_push_swap *push_swap);
	int			(*pb)(t_push_swap *push_swap);
	int			(*ra)(t_push_swap *push_swap);
	int			(*rb)(t_push_swap *push_swap);
	int			(*rr)(t_push_swap *push_swap);
	int			(*rra)(t_push_swap *push_swap);
	int			(*rrb)(t_push_swap *push_swap);
	int			(*rrr)(t_push_swap *push_swap);
	void		(*destroy)(t_push_swap_ops	**self);
};

int	sa(t_push_swap *push_swap);
int	sb(t_push_swap *push_swap);
int	ss(t_push_swap *push_swap);
int	pa(t_push_swap *push_swap);
int	pb(t_push_swap *push_swap);
int	ra(t_push_swap *push_swap);
int	rb(t_push_swap *push_swap);
int	rr(t_push_swap *push_swap);
int	rra(t_push_swap *push_swap);
int	rrb(t_push_swap *push_swap);
int	rrr(t_push_swap *push_swap);

#endif
