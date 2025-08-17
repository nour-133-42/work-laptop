/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:25:54 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/17 13:30:56 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!p)
		return (NULL);
	while (i < ft_strlen(s1) && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2) && s2[i])
	{
		p[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	p[i + ft_strlen(s1)] = '\0';
	return (p);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*i;

// 	i = ft_strjoin("hello", " world");
// 	printf("%s", i);
// }
