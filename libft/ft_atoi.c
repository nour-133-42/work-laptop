/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 05:28:07 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/11 20:14:44 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	r;
	int	s;

	s = 1;
	r = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		s *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			r = r * 10 + (*nptr - '0');
		else
			return (r * s);
		nptr++;
	}
	return (r * s);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char c[] = "+548";
// 	printf("%d\n", ft_atoi(c));
// 	printf("%d", atoi(c));
// }