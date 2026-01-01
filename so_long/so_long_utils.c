/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:56:19 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/01 21:25:44 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player_position(char **map_array, int *px, int *py)
{
	int	i;
	int	j;

	*px = 0;
	*py = 0;
	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'P')
			{
				*px = j;
				*py = i;
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

int	init_images(t_MapData **mapdata)
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
	if (!(*mapdata)->Player_image || !(*mapdata)->Collectable_image
		|| !(*mapdata)->Floor_image || !(*mapdata)->Exit_image
		|| !(*mapdata)->Wall_image)
	{
		free_all(mapdata);
		return (1);
	}
	return (0);
}

int	init_mlx(t_MapData **mapdata)
{
	(*mapdata)->Mlx = mlx_init();
	(*mapdata)->win = mlx_new_window((*mapdata)->Mlx,
			ft_strlen((*mapdata)->map_array[0]) * 32,
			get_map_height((*mapdata)->path) * 32, "so_long");
	if (init_images(mapdata))
		return (1);
	(*mapdata)->collectible_count = count_collectibles((*mapdata)->map_array);
	(*mapdata)->current_collectible_count = 0;
	find_player_position((*mapdata)->map_array, &(*mapdata)->px,
		&(*mapdata)->py);
	find_exit_position((*mapdata)->map_array, &(*mapdata)->ex, &(*mapdata)->ey);
	return (0);
}
