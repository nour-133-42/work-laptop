/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:47 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/13 18:49:52 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*e = s;

	i = ft_strlen(s);
	if (!c)
		return ((char *)e + ft_strlen(s));
	while (i)
	{
		if (e[i] == (unsigned char)c)
			return ((char *)e + i);
		i--;
	}
	if (e[i] == (unsigned char)c)
		return ((char *)e + i);
	return (NULL);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char *i = ft_strrchr("tripouille", 't' + 256);
// 	printf("%s", i);
// }