/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:23:11 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/14 07:13:24 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		j;
	size_t		i;
	const char	*b;

	b = big;
	i = 0;
	if (!little[0])
		return ((char *)b);
	while (*b && i < len)
	{
		j = 0;
		while ((*b == little[j]) && *b && (i < len))
		{
			j++;
			b++;
			i++;
		}
		if (!little[j])
			return ((char *)b - j);
		b -= j;
		i -= j;
		b++;
		i++;
	}
	return (NULL);
}

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *i = ft_strnstr("aaabcabcd", "abcab", 6);
	printf("%s", i);
}