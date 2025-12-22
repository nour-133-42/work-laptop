/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:00:38 by nalshmai          #+#    #+#             */
/*   Updated: 2025/09/09 15:37:38 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_rd(int rd, char **tmp, char **leftover)
{
	if (rd < 0)
	{
		free(*tmp);
		return (NULL);
	}
	free(*tmp);
	*tmp = NULL;
	if (*leftover != NULL)
	{
		if (ft_strlen(*leftover) == 0)
		{
			return (NULL);
		}
		*tmp = ft_strdup(*leftover);
		free(*leftover);
		*leftover = NULL;
		return (*tmp);
	}
	return (*leftover);
}

static char	*line_with_leftover(int fd, char **leftover)
{
	char	*tmp;
	int		rd;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	rd = 1;
	while ((!ft_strchr(*leftover, '\n') || !*leftover) && rd > 0)
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd <= 0)
			return (check_rd(rd, &tmp, leftover));
		tmp[rd] = '\0';
		*leftover = ft_strjoin(leftover, tmp);
	}
	free(tmp);
	return (*leftover);
}

static char	*return_the_line(char *s)
{
	char	*res;
	int		count;

	if (!s)
		return (NULL);
	count = 0;
	while (s[count] && s[count] != '\n')
		count++;
	if (s[count] == '\n')
		count++;
	res = malloc(count + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, count + 1);
	return (res);
}

static char	*left_over(char *s)
{
	char	*res;

	if (!s)
		return (NULL);
	while (*s && *s != '\n')
		s++;
	if (*s == '\n')
		s++;
	if (!*s)
		return (NULL);
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*s;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!leftover)
		leftover = ft_strdup("");
	s = line_with_leftover(fd, &leftover);
	if (!s)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	res = return_the_line(s);
	leftover = left_over(s);
	free(s);
	return (res);
}
