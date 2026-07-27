/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:24:22 by helfayez          #+#    #+#             */
/*   Updated: 2026/07/14 13:11:13 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mallo;
	size_t	lenss;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	lenss = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	mallo = malloc(lenss * sizeof(char) + 1);
	if (!mallo)
		return (NULL);
	while (s1[i] != 0)
	{
		mallo[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		mallo[i++] = s2[j];
		j++;
	}
	mallo[i] = '\0';
	return (mallo);
}
