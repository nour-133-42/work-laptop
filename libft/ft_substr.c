/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:54:25 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 05:13:47 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	p = malloc(len);
	i = 0;
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	return ((char *)p);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*i;

// 	i = ft_substr("2454353", 3, 6);
// 	printf("%s", i);
// }
