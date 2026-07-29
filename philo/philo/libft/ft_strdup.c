/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:19:12 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/14 04:08:57 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const char	*p;

	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	ft_strlcpy((char *)p, s, ft_strlen(s) + 1);
	return ((char *)p);
}

// #include <string.h>

// int	main(void)
// {
// 	printf("%s", ft_strdup(""));
// 	printf("%s", strdup(""));
// }