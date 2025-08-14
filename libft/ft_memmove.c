/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:04:53 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/14 06:44:18 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*p;
	unsigned char		*e;
	size_t				i;

	i = 0;
	p = src;
	e = dest;
	if (!ft_strlen(dest) && !ft_strlen(src))
		return ("");
	if (e > p)
	{
		while (n--)
			e[n] = p[n];
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
// 	// char	c[] = "orem ipsum dolor sit a";
// 	// char	e[] = "4iofjfosdsfeqrfsdfaefsdafew";
// 	// char e[] = "eaammi";
// 	printf("%s", (char *)ft_memmove("", "", -10));
// 	printf("%s", (char *)ft_memmove("", "", -10));
// 	return (0);
// }
