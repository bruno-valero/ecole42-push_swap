/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:22:45 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/22 18:29:54 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nbr_or_space(int c)
{
	return (ft_isdigit(c) || c == ' ');
}

int	is_valid_char(int c)
{
	return (is_nbr_or_space(c) || ft_issign(c));
}
