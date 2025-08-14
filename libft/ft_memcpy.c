/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:37:20 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/14 06:36:59 by nalshmai         ###   ########.fr       */
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
	if (!ft_strlen(dest) && !ft_strlen(src) && (int)n < 0)
		return ("");
	while (n--)
	{
		*e = *p;
		p++;
		e++;
	}
	return (dest);
}

// int	main(void)
// {
// 	// char	c[] = "orem ipsum dolor sit a";
// 	// char	e[] = "4iofjfosdsfeqrfsdfaefsdafew";
// 	// char e[] = "eaammi";
// 	printf("%s", (char *)ft_memcpy("", "", -10));
// 	printf("%s", (char *)memcpy("", "", -10));
// 	return (0);
// }