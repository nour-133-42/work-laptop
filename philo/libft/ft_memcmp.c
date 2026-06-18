/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:40:01 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/14 02:00:21 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p = s1;
	const unsigned char	*e = s2;
	int					i;

	i = 0;
	while (n)
	{
		if (p[i] != e[i])
		{
			return ((unsigned char)p[i] - (unsigned char)e[i]);
		}
		n--;
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int i;
// 	i = 0;
// 	// char	c[] = "orem ipsum dolor sit a";
// 	// char	e[] = "4iofjfosdsfeqrfsdfaefsdafew";
// 	// char e[] = "eaammi";
// 	printf("%d", ft_memcmp("", "", 10));
// 	// write(1, "\n", 1);
// 	printf("%d", memcmp("", "", 10));
// 	return (0);
// }