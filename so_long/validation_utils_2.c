/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:49:23 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/03 18:50:56 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_invalid_characters(char **map_array)
{
	int	i;
	int	j;

	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] != '0' && map_array[i][j] != '1'
				&& map_array[i][j] != 'C' && map_array[i][j] != 'E'
				&& map_array[i][j] != 'P')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_invalid_newline(char *path)
{
	char	*line;
	int		fd;
	int		empty_found;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	empty_found = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			empty_found = 1;
		else if (empty_found)
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	check_after_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**copy_map(t_MapData **map_data)
{
	int		i;
	int		height;
	char	**new_map;

	height = get_map_height((*map_data)->path);
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while ((*map_data)->map_array[i])
	{
		new_map[i] = malloc(ft_strlen((*map_data)->map_array[i]) + 1);
		if (!new_map[i])
			return (NULL);
		ft_strlcpy(new_map[i], (*map_data)->map_array[i],
			ft_strlen((*map_data)->map_array[i]) + 1);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
