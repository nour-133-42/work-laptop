/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:49:23 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/29 16:39:14 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_invalid_newline(char *path)
{
		char	*line;
		int		fd;

		fd = open(path, O_RDONLY);
		line = get_next_line(fd);
		while (line)
		{
			if (ft_strlen(line) == 0)
			{
				while (line)
				{
					if (ft_strlen(line) != 0)
					{
						close(fd);
						free(line);
						return(1);
					}
					line = get_next_line(fd);
				}
			}
			line = get_next_line(fd);
		}
		close(fd);
		free(line);
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
	int	i;
	int j;
	char	**new_map;

	new_map = malloc(get_map_height((*map_data)->path) + 1);
	i = 0;
	while ((*map_data)->map_array[i])
	{
		new_map[i] = malloc(ft_strlen((*map_data)->map_array[i]) + 1);
		new_map[i] = (*map_data)->map_array[i];
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
