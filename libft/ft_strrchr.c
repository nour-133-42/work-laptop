/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:47 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 04:38:35 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*e = s;

	i = ft_strlen(s) - 1;
	while (e[i])
	{
		if (e[i] == c)
		{
			return ((char *)e + i);
		}
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char *i = ft_strrchr("2454353", '5');
// 	printf("%s", i);
// }