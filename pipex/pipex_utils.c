/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:02:53 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/12 16:30:05 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

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

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*e = s;

	i = 0;
	if (!s)
		return (NULL);
	if (!c)
		return ((char *)e + ft_strlen(s));
	while (i < ft_strlen(s))
	{
		if (e[i] == (unsigned char)c)
			return ((char *)e + i);
		i++;
	}
	if (e[i] == (unsigned char)c)
		return ((char *)e + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!p || !s1 || !s2)
		return (NULL);
	while (i < ft_strlen(s1) && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2) && s2[i])
	{
		p[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	p[i + ft_strlen(s1)] = '\0';
	return (p);
}

int	create_children(t_pipex *pipex, char **argv, char **envp, int *pid)
{
	pid[0] = fork();
	if (pid[0] == -1)
		return (1);
	if (pid[0] == 0)
		child_one(pipex, argv, envp);
	pid[1] = fork();
	if (pid[1] == -1)
		return (1);
	if (pid[1] == 0)
		child_two(pipex, argv, envp);
	return (0);
}
