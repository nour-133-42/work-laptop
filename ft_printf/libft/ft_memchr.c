/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:09:35 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/14 02:10:30 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*e;

	e = s;
	i = 0;
	while (n--)
	{
		if (e[i] == (unsigned char)c)
		{
			return ((char *)e + i);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	int i;
// 	i = 0;
// 	// char	c[] = "orem ipsum dolor sit a";
// 	// char	e[] = "4iofjfosdsfeqrfsdfaefsdafew";
// 	// char e[] = "eaammi";
// 	printf("%s", (char *)ft_memchr("", -1, -1));
// 	// write(1, "\n", 1);
// 	printf("%s", (char *)memchr("", -1, -1));
// 	return (0);
// }