/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:33:32 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/22 20:51:16 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_lines_length(int fd, int length)
{
	char	*line;
	int		current_length;

	line = get_next_line(fd);
	while (line)
	{
		current_length = ft_strlen(line);
		// if (current_length > 0 && line[current_length - 1] == '\n')
		// 	current_length--;
		if (current_length != length)
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}

int	map_rectangle(char *path)
{
	int	fd;
	int	length;

	length = line_length(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCould not open file\n", 27);
		return (1);
	}
	if (check_lines_length(fd, length) == 1)
	{
		close(fd);
		write(2, "Error\nMap is not rectangular\n", 29);
		return (1);
	}
	close(fd);
	return (0);
}

int	map_walls(char **map_array)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	i = -1;
	j = -1;
	rows = 0;
	cols = 0;
	while (map_array[rows][0])
		rows++;
	while (map_array[0][cols])
		cols++;
	while (map_array[0][++j])
	{
		if (map_array[0][j] != '1' || map_array[rows - 1][j] != '1')
			return (1);
	}
	while (map_array[++i][0])
	{
		if (map_array[i][0] != '1' || map_array[i][cols - 1] != '1')
			return (1);
	}
	return (0);
}

int	map_elements(char **map_array)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	i = -1;
	while (map_array[++i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'P')
				p++;
			else if (map_array[i][j] == 'E')
				e++;
			else if (map_array[i][j] == 'C')
				c++;
			j++;
		}
	}
	return (!(p == 1 && e == 1 && c >= 1));
}
