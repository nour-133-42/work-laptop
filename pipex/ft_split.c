/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:04:24 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/07 18:04:58 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

static char	*ft_strchr_me(const char *s, int c)
{
	int			i;
	const char	*e;

	e = s;
	i = 0;
	if (!s)
		return (NULL);
	if (!c)
		return ((char *)e + ft_strlen(s));
	while (e[i])
	{
		if (e[i] == (unsigned char)c)
			return ((char *)e + i);
		i++;
	}
	return (NULL);
}

static size_t	count_word(char *x, char c)
{
	int		e;
	int		h;
	char	*w;

	e = 0;
	h = 0;
	w = x;
	if (!x)
		return (0);
	if ((ft_strlen(x) == 0))
		return (0);
	while (ft_strchr_me(w, c) && c)
	{
		h++;
		while (*w == c)
			w++;
		if (*w)
			e++;
		w = ft_strchr_me(w, c);
	}
	if (!c || e == 0)
		e = 1;
	return (e);
}

static char	*make_word(const char *s, char c)
{
	int		e;
	char	*word;
	int		i;

	e = 0;
	while (s[e] && !(s[e] == c))
		e++;
	word = malloc(e + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < e)
	{
		word[i] = s[i];
		i++;
	}
	word[e] = '\0';
	return (word);
}

static char	**free_alll(char **r, int i)
{
	while (i >= 0)
		free(r[i--]);
	free(r);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	j;

	j = 0;
	r = malloc((count_word((char *)s, c) + 1) * sizeof(char *));
	if (!r || !s)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			r[j] = make_word(s, c);
			if (!(r[j++]))
				return (free_alll(r, j - 1));
			while (*s && !(*s == c))
				s++;
		}
	}
	r[j] = NULL;
	return ((char **)r);
}
