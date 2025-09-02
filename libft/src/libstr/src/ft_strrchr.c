/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:02:52 by brunofer          #+#    #+#             */
/*   Updated: 2025/09/02 18:59:28 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last_position;
	int	i;

	c = c % 256;
	last_position = -1;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			last_position = i;
	if (s[i] == c)
		last_position = i;
	if (last_position == -1)
		return (NULL);
	return ((char *)&s[last_position]);
}
