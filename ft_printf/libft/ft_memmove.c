/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:04:53 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/17 13:27:19 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*p;
	unsigned char		*e;
	size_t				i;

	i = 0;
	p = src;
	e = dest;
	if (p[0] == '\0' && e[0] == '\0')	
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
// 	char	c[] = "";
// 	char	e[] = "";

// 	char e[] = "eaammi";
// 	printf("%s", (char *)ft_memmove(c, e, -1));
// 	printf("%s", (char *)memmove(c, e, -1));
// 	return (0);
// }
