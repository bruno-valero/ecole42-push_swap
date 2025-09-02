/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_char_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:33:27 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 18:59:18 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

void	*ft_destroy_char_matrix(char ***char_matrix_ref)
{
	int	i;

	i = -1;
	while ((*char_matrix_ref)[++i])
	{
		free((*char_matrix_ref)[i]);
		(*char_matrix_ref)[i] = NULL;
	}
	free(*char_matrix_ref);
	*char_matrix_ref = NULL;
	return (NULL);
}
