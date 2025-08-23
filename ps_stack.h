/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:45:50 by valero            #+#    #+#             */
/*   Updated: 2025/08/23 11:30:27 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include "libft.h"

typedef struct s_ps_stack			t_ps_stack;
typedef struct s_ps_node_content	t_ps_node_content;

struct s_ps_stack
{
	int					is_stack_a;
	int					bigger;
	int					smaller;
	t_stack				*stack;
	void				(*update_on_transfer)(
			t_ps_stack *self, t_ps_stack *other_stack);
	int					(*compare_node)(void *self_content, void *content);
	t_ps_node_content	*(*get_content)(t_stack_node *node);
	void				(*destroy)(struct s_ps_stack	**self);
};

struct s_ps_node_content
{
	int				value;
	t_stack_node	*target_node;
};

t_ps_stack			*new_ps_stack(int is_stack_a);
t_ps_node_content	*new_ps_node_content(int number);
void				ps_stack_destroy(t_ps_stack	**self);
void				ps_stack_update_on_transfer(
						t_ps_stack *self, t_ps_stack *other_stack);
int					compare_ps_node(void *self_content, void *content);
void				ps_node_content_destroy(void *node);
t_ps_node_content	*get_ps_content(t_stack_node *node);
void				*destroy_ps_stacks(
						t_ps_stack *stack_a, t_ps_stack *stack_b);

#endif
