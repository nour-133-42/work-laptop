/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:23:06 by nalshmai          #+#    #+#             */
/*   Updated: 2025/08/11 18:42:30 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && n)
	{
		if (*s1 != *s2)
		{
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	int i = ft_strncmp("2454353", "5", 1);
// 	printf("%d", i);
// }