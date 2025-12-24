/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:56:19 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/24 17:59:42 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player_position(char **map_array, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'P')
			{
				*player_x = j;
				*player_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	line_length(char *path)
{
	int		fd;
	char	*line;
	int		length;

	length = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCould not open file\n", 27);
		return (0);
	}
	line = get_next_line(fd);
	if (line)
	{
		while (line[length])
			length++;
	}
	free(line);
	close(fd);
	return (length);
}

int	count_collectibles(char **map_array)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (map_array[++i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'C')
				count++;
			j++;
		}
	}
	return (count);
}
