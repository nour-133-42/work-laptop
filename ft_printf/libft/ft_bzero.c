/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:58:04 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 05:43:11 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p = 0;
		p++;
	}
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char c[] = {1, 2, 3, 4, 5};
// 	ft_bzero(c, 5);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("Element at index %c: %c\n", i, c[i]);
// 	}
// 	// printf("%*d",ft_memset(c,4,5));
// 	return (0);
// }