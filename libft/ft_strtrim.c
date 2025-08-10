/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:48:06 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 06:21:44 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	unsigned int	i;
// 	unsigned int	c;

// 	i = 0;
// 	c = 0;
// 	while (src[c])
// 		c++;
// 	if (size < 1)
// 		return (c);
// 	while (src[i] && (i < size))
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (c);
// }

// char	*ft_strnstr(const char *big, const char *little, size_t len)
// {
// 	int			j;
// 	int			i;
// 	const char	*b;

// 	b = big;
// 	i = 0;
// 	if (!little[0])
// 		return ((char *)b);
// 	while (*b && i < (int)len)
// 	{
// 		j = 0;
// 		while ((*b == little[j]) && *b && i < (int)len)
// 		{
// 			j++;
// 			b++;
// 			i++;
// 		}
// 		if (!little[j])
// 			return ((char *)b - j);
// 		b++;
// 		i++;
// 	}
// 	return (0);
// }

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*x;
	size_t	i;
	size_t	n;

	i = 0;
	p = malloc(ft_strlen(s1) + 2);
	x = malloc(ft_strlen(s1) + 1);
	n = ft_strlen(set);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen(s1));
	x = ft_strnstr(p, set, ft_strlen(s1));
	if (x)
	{
		while (x[i + n])
		{
			x[i] = x[i + n];
			i++;
		}
		x[i] = '\0';
	}
	return ((char *)p);
}

// int	main(void)
// {
// 	char	*i;

// 	i = ft_strtrim("welcome", "com");
// 	printf("%s", i);
// }
