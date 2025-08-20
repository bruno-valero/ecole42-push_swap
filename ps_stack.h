/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:45:50 by valero            #+#    #+#             */
/*   Updated: 2025/08/20 13:33:02 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include "libft.h"

typedef struct s_ps_stack
{
	int		is_stack_a;
	int		bigger;
	int		smaller;
	t_stack	*stack;
	void	(*destroy)(struct s_ps_stack	**self);
}	t_ps_stack;

typedef struct s_ps_node_content
{
	int				value;
	t_stack_node	*target_node;
}	t_ps_node_content;

t_ps_node_content	*new_node_content(int number);
void				ps_stack_destroy(t_ps_stack	**self);

#endif
