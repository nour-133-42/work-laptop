/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:04:53 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 05:47:59 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*p;
	unsigned char		*e;
	size_t				i;

	if ((dest == NULL && src == NULL) || n == 0)
		return (NULL);
	i = 0;
	p = src;
	e = dest;
	if (e > p)
	{
		while (n--)
		{
			e[n] = p[n];
		}
	}
	else
	{
		while (i < n)
		{
			e[i] = p[i];
			i++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char c[] = "hello";
// 	//char e[] = "eaammi";

// 	ft_memmove(c - 3,c, 5);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("Element at index %c: %c\n", i, c[i]);
// 	}
// 	// printf("%*d",ft_memset(c,4,5));
// 	return (0);
// }
