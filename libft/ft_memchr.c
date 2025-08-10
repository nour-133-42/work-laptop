/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:09:35 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 08:24:35 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int			i;
	const char	*e;

	e = s;
	i = 0;
	while (e[i] && n--)
	{
		if (e[i] == c)
		{
			return ((char *)e + i);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char *i = memchr("2454353", '5', 3);
// 	printf("%s", i);
// }