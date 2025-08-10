/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:04:24 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/10 08:55:06 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "libft.h"

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

char	**ft_split(char const *s, char c)
{
	unsigned char	*p;
	unsigned char	**r;
	size_t			i;
	size_t			j;
	size_t			n;

	i = 0;
	n = 0;
	j = 0;
	p = malloc(ft_strlen(s) * 2 + 1);
	r = malloc(ft_strlen(s) * 2 + 1);
	if (!p || !r)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] != c)
			p[n++] = s[i++];
		r[j++] = p;
		if (!s[i++])
			break ;
		p = malloc(ft_strlen(s) * 2 + 1);
		n = 0;
	}
	r[j] = NULL;
	return ((char **)r);
}

// int	main(void)
// {
// 	char **c;
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	c = ft_split("hello world 42", ' ');
// 	while (c[i])
// 	{
// 		printf("%s\n", c[i]);
// 		i++;
// 	}
// 	// c = split("hel   lo,mtrdjgvr,youghvuyg", 'l');
// 	// while (c[i])
// 	// {
// 	// 	printf("%s\n", c[i]);
// 	// 	i++;
// 	// }
// }