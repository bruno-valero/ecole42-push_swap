/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:49 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/20 22:26:37 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ps_stack.h"
# include "validate.h"

typedef struct s_push_swap t_push_swap;
typedef struct s_push_swap_ops t_push_swap_ops;

/**
	push swap operations
*/
struct s_push_swap_ops
{
	int			(*rotate)(t_ps_stack *ps_sptack);
	int			(*rotate_both)(t_push_swap	*push_swap);
	int			(*rotate_reverse)(t_ps_stack *ps_stack);
	int			(*rotate_reverse_both)(t_push_swap	*push_swap);
	int			(*swap)(t_ps_stack *push_swap);
	int			(*swap_both)(t_push_swap	*push_swap);
	int			(*stack1_push_to_stack2)(t_push_swap *push_swap, int push_a_to_b);
	void		(*destroy)(t_push_swap_ops	**self);
};

/**
	push swap main struct
*/
struct s_push_swap
{
	t_ps_stack		*stack_a;
	t_ps_stack		*stack_b;
	t_push_swap_ops	*ops;
	int				(*fill_stack_a)(t_push_swap *self, int number);
	void			(*destroy)(t_push_swap	**self);
};

// ****************** push_swap_ops ******************
void	push_swap_ops_destroy(t_push_swap_ops	**self);

// ----------- rotate ops -----------
int		rotate_stack(t_ps_stack *ps_sptack);
int		rotate_stack_both(t_push_swap	*push_swap);
int		rotate_reverse_stack(t_ps_stack *ps_stack);
int		rotate_reverse_stack_both(t_push_swap	*push_swap);
// -	---------- swap ops -----------
int		swap_stack(t_ps_stack *push_swap);
int		swap_stack_both(t_push_swap *push_swap);
int		stack1_push_to_stack2(t_push_swap *push_swap, int push_a_to_b);

// ******************************************************

// push swap
void	push_swap_destroy(t_push_swap	**self);
int		fill_stack_a(t_push_swap *self, int number);

#endif
