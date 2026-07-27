/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:31:08 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/25 17:29:06 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	i = 0;
	if (dl >= size)
		return (ft_strlen(src) + size);
	while (src[i] && (dl + i + 1) < size)
	{
		dst[dl + i] = src[i];
		i++;
	}
	if (dl + i < size)
		dst[dl + i] = '\0';
	return (dl + sl);
}
// #include <bsd/string.h>
// int main()
// {
// 	printf("%zu\n",ft_strlcat("Hello", "World", 0));
// 	printf("%zu", strlcat("Hello", "World", 0));
// }
