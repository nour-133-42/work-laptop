/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:20:29 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/13 22:29:48 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;

	if (size == 0 && nmemb == 0)
	{
		p = malloc(nmemb * size);
		return (p);
	}
	p = malloc(nmemb * size);
	i = 0;
	if (!p)
		return (NULL);
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
/*int	main(void)
{
	//void *str = ft_calloc(0, 0);

	//if (str == ((void *)0))
	//	printf("nooooo");
	//free(str);
	char *str = malloc(3); 
	printf("%c,%c,%c",str[0],str[1],str[2]);
}*/