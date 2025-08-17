/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:37:20 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/17 20:18:03 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*p;
	unsigned char		*e;
	size_t				i;

	i = 0;
	p = src;
	e = dest;
	if (p[0] == '\0' && e[0] == '\0')
		return ("");
	while (i < n)
	{
		*e = *p;
		p++;
		e++;
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char c[] = "sehvt";
// 	char e[] = "hello";

// 	// char e[] = "eaammi";
// 	printf("%s", (char *)ft_memcpy(c, e, 6));
// 	printf("%s", (char *)memcpy(c, e, 6));
// 	return (0);
// }