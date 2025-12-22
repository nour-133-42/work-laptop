/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:00:35 by nalshmai          #+#    #+#             */
/*   Updated: 2025/09/08 19:13:07 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc((ft_strlen(*s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str != NULL)
	{
		while ((*s1)[i])
		{
			str[i + j] = (*s1)[i];
			i++;
		}
		while (s2[j])
		{
			str[i + j] = s2[j];
			j++;
		}
		str[i + j] = '\0';
	}
	free(*s1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	const char	*p;

	if (!s)
		return (NULL);
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	ft_strlcpy((char *)p, s, ft_strlen(s) + 1);
	return ((char *)p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = 0;
	if (!src || !dst)
		return (0);
	while (src[c])
		c++;
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
