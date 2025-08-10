/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:23:11 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 05:57:36 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			j;
	int			i;
	const char	*b;

	b = big;
	i = 0;
	if (!little[0])
		return ((char *)b);
	while (*b && i < (int)len)
	{
		j = 0;
		while ((*b == little[j]) && *b && i < (int)len)
		{
			j++;
			b++;
			i++;
		}
		if (!little[j])
			return ((char *)b - j);
		b++;
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char *i = ft_strnstr("2454353", "543", 6);
// 	printf("%s", i);
// }