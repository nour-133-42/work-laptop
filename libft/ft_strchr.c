/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:52:40 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/05 17:14:31 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*e;

	e = s;
	i = 0;
	while (e[i])
	{
		if (e[i] == c)
		{
			return ((char *)e + i);
		}
		i++;
	}
	return (NULL);
}

// #include <unistd.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char *i = ft_strchr("2454353",'5');
// 		printf("%s",i);
// }