/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:04:57 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/14 01:54:23 by nalshmai         ###   ########.fr       */
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

// int	main(void)
// {
// 	// char	c[] = "orem ipsum dolor sit a";
// 	// char	e[] = "4iofjfosdsfeqrfsdfaefsdafew";
// 	// char e[] = "eaammi";
// 	//write(1, ft_memset("", 10, -1), 22);
// 	write(1, "\n", 1);
// 	write(1, memset("", 10, -1), 22);
// 	return (0);
// }