/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 20:33:32 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/03 19:08:05 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_MapData **md)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		(*md)->c_count--;
	if (map[y][x] == 'E')
	{
		(*md)->exit_flag = 1;
		return ;
	}
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, md);
	flood_fill(map, x - 1, y, md);
	flood_fill(map, x, y + 1, md);
	flood_fill(map, x, y - 1, md);
}

static int	check_lines_length(char **map)
{
	int	current_length;
	int	length;
	int	i;

	i = 0;
	length = ft_strlen(map[0]);
	while (map[i])
	{
		current_length = ft_strlen(map[i]);
		if (current_length != length && current_length)
			return (1);
		i++;
	}
	return (0);
}

int	map_rectangle(char *path, t_MapData **mapdata)
{
	int		fd;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCould not open file\n", 27);
		free(*mapdata);
		return (1);
	}
	close(fd);
	map = readmap(path);
	if (check_lines_length(map) == 1)
	{
		close(fd);
		free(*mapdata);
		write(2, "Error\nMap is not rectangular\n", 29);
		free_map(map);
		return (1);
	}
	free_map(map);
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
	while (map_array[rows] && ft_strlen(map_array[rows]))
		rows++;
	while (map_array[0][cols])
		cols++;
	while (++j < cols)
	{
		if (map_array[0][j] != '1' || map_array[rows - 1][j] != '1')
			return (1);
	}
	while (++i < rows)
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
