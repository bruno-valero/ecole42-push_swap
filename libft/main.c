/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:59:37 by brunofer          #+#    #+#             */
/*   Updated: 2025/08/21 12:03:30 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	**str;

	str = ft_split("ola eu sou o bruno", ' ');
	printf("[0]: %s\n", str[0]);
	printf("[1]: %s\n", str[1]);
	printf("[2]: %s\n", str[2]);
	printf("[3]: %s\n", str[3]);
	printf("[4]: %s\n", str[4]);
}
