/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:04:57 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 05:48:43 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p = c;
		p++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(void)
// {
// 	int c[] = {1, 2, 3, 4, 5};
// 	ft_memset(c, 6, 5 * 4);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("Element at index %c: %c\n", i, c[i]);
// 	}
// 	// printf("%*d",ft_memset(c,4,5));
// 	return (0);
// }