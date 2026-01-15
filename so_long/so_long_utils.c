/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:56:19 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/05 15:18:47 by nalshmai         ###   ########.fr       */
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
	line = get_next_line(fd, 1);
	if (line)
		length = ft_strlen(line);
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
	(*mapdata)->floor_image = mlx_xpm_file_to_image((*mapdata)->mlx,
			"textures/download.xpm", &w, &h);
	(*mapdata)->exit_image = mlx_xpm_file_to_image((*mapdata)->mlx,
			"textures/exit.xpm", &w, &h);
	(*mapdata)->player_image = mlx_xpm_file_to_image((*mapdata)->mlx,
			"textures/player_floor_background.xpm", &w, &h);
	(*mapdata)->collectable_image = mlx_xpm_file_to_image((*mapdata)->mlx,
			"textures/lettuce_with_background.xpm", &w, &h);
	(*mapdata)->wall_image = mlx_xpm_file_to_image((*mapdata)->mlx,
			"textures/wall.xpm", &w, &h);
	if (!(*mapdata)->player_image || !(*mapdata)->collectable_image
		|| !(*mapdata)->floor_image || !(*mapdata)->exit_image
		|| !(*mapdata)->wall_image)
	{
		free_all(mapdata);
		return (1);
	}
	return (0);
}

int	init_mlx(t_MapData **mapdata)
{
	first_init(mapdata);
	(*mapdata)->mlx = mlx_init();
	if (!(*mapdata)->mlx)
		return (free_all(mapdata));
	(*mapdata)->win = mlx_new_window((*mapdata)->mlx,
			ft_strlen((*mapdata)->map_array[0]) * 32,
			(get_map_height((*mapdata)->path) - count_empty_lines(mapdata))
			* 32, "so_long");
	if (!(*mapdata)->win)
		return (free_all(mapdata));
	if (init_images(mapdata))
		return (1);
	(*mapdata)->c_count = count_collectibles((*mapdata)->map_array);
	(*mapdata)->current_c_count = 0;
	find_player_position((*mapdata)->map_array, &(*mapdata)->px,
		&(*mapdata)->py);
	find_exit_position((*mapdata)->map_array, &(*mapdata)->ex, &(*mapdata)->ey);
	(*mapdata)->moves = 0;
	return (0);
}
