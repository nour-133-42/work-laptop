/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:01:24 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/12 22:58:53 by nalshmai         ###   ########.fr       */
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
	while (src[i] && (i < size - 1))
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
// 	// char *c = "lorem ipsum";
// 	char e1[10] = "wefsd"; // Writable destination buffer
// 	// char e2[10] = "wefsd";  // Another for comparison with real strlcpy

// 	ft_strlcpy(e1, "lorem ipsum", 11);
// 	// printf("%d", r);
// 	write(1, "\n", 1);
// 	write(1, e1, 15);

// 	return (0);
// }