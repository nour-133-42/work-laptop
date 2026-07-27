/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:15:58 by helfayez          #+#    #+#             */
/*   Updated: 2025/08/25 16:39:04 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1 == s2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*mallo;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1) - 1;
	while (s1[first] != '\0' && ft_set(s1[first], set))
		first++;
	while (last > first && ft_set(s1[last], set))
		last--;
	if (first > last)
		return (ft_strdup(""));
	mallo = malloc((last - first) + 2);
	if (!mallo)
		return (NULL);
	ft_strlcpy(mallo, s1 + first, last - first + 2);
	return (mallo);
}
