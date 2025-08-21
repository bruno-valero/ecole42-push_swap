/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:26:49 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/21 18:42:56 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ps_stack.h"
# include "validate.h"
# include "push_swap_ops.h"
# include <stdio.h>

typedef struct s_push_swap		t_push_swap;

/**
	push swap main struct
*/
struct s_push_swap
{
	t_ps_stack		*stack_a;
	t_ps_stack		*stack_b;
	t_push_swap_ops	*ops;
	int				(*fill_stack_a)(t_push_swap *self, int number);
	int				(*extract_input)(t_push_swap *self, int argc, char **argv);
	void			(*destroy)(t_push_swap	**self);
};

// ****************** push_swap_ops ******************
void			push_swap_ops_destroy(t_push_swap_ops	**self);

// -----		------ rotate ops -----------
int				rotate_stack(t_ps_stack *ps_sptack);
int				rotate_stack_both(t_push_swap	*push_swap);
int				rotate_reverse_stack(t_ps_stack *ps_stack);
int				rotate_reverse_stack_both(t_push_swap	*push_swap);
// -	---------- swap ops -----------
int				swap_stack(t_ps_stack *push_swap);
int				swap_stack_both(t_push_swap *push_swap);
int				push_stack1_to_stack2(t_push_swap *push_swap, int push_a_to_b);

// ******************************************************

// push swap
t_push_swap		*new_push_swap(void);
void			push_swap_destroy(t_push_swap	**self);
int				fill_stack_a(t_push_swap *self, int number);

#endif
