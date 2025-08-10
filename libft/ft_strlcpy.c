/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:01:24 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 06:13:04 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = 0;
	while (src[c])
		c++;
	if (size < 1)
		return (c);
	while (src[i] && (i < size))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (c);
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char *c = "hello";
// 	char e1[10] = "wefsd"; // Writable destination buffer
// 	// char e2[10] = "wefsd";  // Another for comparison with real strlcpy

// 	int r = ft_strlcpy(e1, c, 5);
// 	printf("ft_strlcpy:\nsrc: %s\ndst: %s\nret: %d\n", c, e1, r);

// 	return (0);
// }