/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:02:52 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/20 15:29:37 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

long int	ft_atol(const char *nptr)
{
	long int	result;
	int			i;
	int			sign;
	char		*nbstr;

	nbstr = (char *)nptr;
	while (*nbstr == ' ' || (*nbstr > 8 && *nbstr < 14))
		nbstr++;
	sign = 1;
	if (nbstr[0] == '-' || nbstr[0] == '+')
	{
		if (nbstr[0] == '-')
			sign = -1;
		nbstr++;
	}
	result = 0;
	i = -1;
	while (ft_isdigit(nbstr[++i]))
		result = result * 10 + (nbstr[i] - '0');
	return (result * sign);
}
