/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:49 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/19 16:02:17 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_ps_stack
{
	int		is_stack_a;
	t_stack	*stack;
	void	(*destroy)(struct s_ps_stack	**self,
			void (*del_node_content)(void *content));
}	t_ps_stack;

/**
	push swap operations
*/
typedef struct s_push_swap_ops
{
	int			(*rotate)(t_ps_stack *push_swap);
	int			(*rotate_both)(
			t_ps_stack *push_swap_a, t_ps_stack *push_swap_b);
	int			(*rotate_reverse)(t_ps_stack *push_swap);
	int			(*rotate_reverse_both)(
			t_ps_stack *push_swap_a, t_ps_stack *push_swap_b);
	int			(*swap)(t_ps_stack *push_swap);
	int			(*swap_both)(t_ps_stack *push_swap_a, t_ps_stack *push_swap_b);
	int			(*stack1_push_to_stack2)(
			t_ps_stack *push_swap_a, t_ps_stack *push_swap_b, int push_a_to_b);
	void		(*destroy)(t_push_swap_ops	**self);
}	t_push_swap_ops;

/**
	push swap main struct
*/
typedef struct s_push_swap
{
	t_ps_stack		*stack_a;
	t_ps_stack		*stack_b;
	t_push_swap_ops	*ops;
	void			(*destroy)(
			t_push_swap	**self, void (*del_content_node)(void *content));
}	t_push_swap;


// push_swap_stack
void	ps_stack_destroy(
			t_ps_stack	**self, void (*del_node_content)(void *content));

// ****************** push_swap_ops ******************
void	push_swap_ops_destroy(t_push_swap_ops	**self);

// ----------- rotate ops -----------
int		rotate_stack(t_ps_stack *push_swap);
int		rotate_stack_both(t_ps_stack *push_swap_a, t_ps_stack *push_swap_b);
int		rotate_reverse_stack(t_ps_stack *push_swap);
int		rotate_reverse_stack_both(
			t_ps_stack *push_swap_a, t_ps_stack *push_swap_b);
// -	---------- swap ops -----------
int		swap_stack(t_ps_stack *push_swap);
int		swap_stack_both(t_ps_stack *push_swap_a, t_ps_stack *push_swap_b);
int		stack1_push_to_stack2(t_ps_stack *push_swap_a,
			t_ps_stack *push_swap_b, int push_a_to_b);

// ******************************************************

// push swap
void	push_swap_destroy(
		t_push_swap	**self, void (*del_content_node)(void *content));

#endif
