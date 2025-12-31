/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:56:19 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/31 19:37:26 by nalshmai         ###   ########.fr       */
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

void	init_images(t_MapData **mapdata)
{
	int	w;
	int	h;

	h = 32;
	w = 32;
	(*mapdata)->Floor_image = mlx_xpm_file_to_image((*mapdata)->Mlx,
			"textures/download.xpm", &w, &h);
	(*mapdata)->Exit_image = mlx_xpm_file_to_image((*mapdata)->Mlx,
			"textures/exit.xpm", &w, &h);
	(*mapdata)->Player_image = mlx_xpm_file_to_image((*mapdata)->Mlx,
			"textures/player_floor_background.xpm", &w, &h);
	(*mapdata)->Collectable_image = mlx_xpm_file_to_image((*mapdata)->Mlx,
			"textures/lettuce_with_background.xpm", &w, &h);
	(*mapdata)->Wall_image = mlx_xpm_file_to_image((*mapdata)->Mlx,
			"textures/wall.xpm", &w, &h);
}

int	init_mlx(t_MapData **mapdata)
{
	(*mapdata)->Mlx = mlx_init();
	(*mapdata)->win = mlx_new_window((*mapdata)->Mlx, 64 * 32, 64 * 32,
			"so_long");
	init_images(mapdata);
}
