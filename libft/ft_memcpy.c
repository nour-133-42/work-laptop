/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:37:20 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 05:47:20 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*p;
	unsigned char		*e;

	p = src;
	e = dest;
	while (n--)
	{
		*e = *p;
		p++;
		e++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char c[] = "hello";
// 	char e[] = "eaamm";

// 	ft_memcpy(e,c, 5);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("Element at index %c: %c\n", i, e[i]);
// 	}
// 	// printf("%*d",ft_memset(c,4,5));
// 	return (0);
// }