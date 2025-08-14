/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:52:40 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/13 19:09:42 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*e = s;

	i = 0;
	if (!c)
		return ((char *)e + ft_strlen(s));
	while (i < ft_strlen(s))
	{
		if (e[i] == (unsigned char)c)
			return ((char *)e + i);
		i++;
	}
	if (e[i] == (unsigned char)c)
		return ((char *)e + i);
	return (NULL);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*i;

// 	i = ft_strchr("teste", 1024);
// 	printf("%s", i);
// }

// int	test_strchr(void)
// {
// 	int res;

// 	res = 1;
// 	res = single_test_strchr(1, "teste", 't') && res;
// 	res = single_test_strchr(2, "teste", 'e') && res;
// 	res = single_test_strchr(3, "teste", '\0') && res;
// 	res = single_test_strchr(4, "teste", 'a') && res;
// 	res = single_test_strchr(5, "teste", 'e' + 256) && res;
// 	res = single_test_strchr(6, "teste", 1024) && res;
// 	return (res);
// }