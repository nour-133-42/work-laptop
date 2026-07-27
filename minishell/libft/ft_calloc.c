/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:09:25 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/26 14:08:55 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*mallo;
	size_t			total;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	mallo = malloc(total);
	if (!mallo)
		return (NULL);
	while (i < total)
	{
		mallo[i] = 0;
		i++;
	}
	return ((void *)mallo);
}
