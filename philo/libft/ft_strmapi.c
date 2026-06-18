/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 01:43:04 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/13 23:29:28 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*p;

	if (!s || !f)
		return (NULL);
	i = 0;
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

// #include <string.h>

// char	mapi(unsigned int i, char c)
// {
// 	static int	indexArray[11] = {0};

// 	if (i > 10 || indexArray[i] == 1)
// 		write(1, "wrong index\n", 12);
// 	else
// 		indexArray[i] = 1;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	else if (c >= 'A' && c <= 'Z')
// 		return (c + 32);
// 	else
// 		return (c);
// }
// int	main(int argc, const char *argv[])
// {
// 	char *str;
// 	char *strmapi;

// 	str = (char *)malloc(sizeof(*str) * 12);
// 	if (argc == 1 || !str)
// 		return (0);
// 	else if (atoi(argv[1]) == 1)
// 	{
// 		strcpy(str, "LoReM iPsUm");
// 		strmapi = ft_strmapi(str, &mapi);
// 		ft_print_result(strmapi);
// 		if (strmapi == str)
// 			ft_print_result("\nA new string was not returned");
// 		if (strmapi[11] != '\0')
// 			ft_print_result("\nString is not null terminated");
// 	}
// 	return (0);
// }