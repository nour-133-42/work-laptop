/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:09:59 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/26 14:11:36 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*c;

	i = 0;
	s = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (i < n)
	{
		if (s[i] != c[i])
			return (s[i] - c[i]);
		i++;
	}
	return (0);
}
