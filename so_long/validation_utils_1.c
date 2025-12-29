/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:33:32 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/29 15:59:21 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(char **map_array, int x, int y, int *collectible_count)
{
	if (map_array[y][x] == '1' || map_array[y][x] == 'E'
		|| map_array[y][x] == 'V')
		return (0);
	if (map_array[y][x] == 'C')
		(*collectible_count)--;
	map_array[y][x] = 'V';
	flood_fill(map_array, x + 1, y, collectible_count);
	flood_fill(map_array, x - 1, y, collectible_count);
	flood_fill(map_array, x, y + 1, collectible_count);
	flood_fill(map_array, x, y - 1, collectible_count);
	return (1);
}

static int	check_lines_length(int fd, int length, int hight)
{
	char	*line;
	int		current_length;

	line = get_next_line(fd);
	while (line)
	{
		current_length = ft_strlen(line);
		if (current_length > 0 && line[current_length - 1] != '\n')
			current_length++;
		if (current_length != length || --hight < 0)
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
	if (check_lines_length(fd, length, get_map_height(path)) == 1)
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

	i = 0;
	j = 0;
	rows = 0;
	cols = 0;
	while (map_array[rows])
		rows++;
	while (map_array[0][cols])
		cols++;
	while (j < cols - 1)
	{
		if (map_array[0][j] != '1'
			|| map_array[rows - 1][j] != '1')
			return (1);
		j++;
	}
	while (i < rows)
	{
		if (map_array[i][0] != '1'
			|| map_array[i][cols - 2] != '1')
			return (1);
		i++;
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
