/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:40:01 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 02:06:17 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p = s1;
	const unsigned char	*e = s2;
	int					i;

	i = 0;
	while (p[i] && n)
	{
		if (p[i] != e[i])
		{
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	else
		return (*p - *e);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	int i = ft_memcmp("2454353", "5", 1);
// 	printf("%d", i);
// }