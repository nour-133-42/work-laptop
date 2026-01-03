/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:14:49 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/03 19:30:20 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**readmap(char *path)
{
	char	*line;
	char	**result;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	result = malloc(sizeof(char *) * (get_map_height(path) + 1));
	if (!result)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		result[i++] = line;
		line = get_next_line(fd);
	}
	result[i] = NULL;
	close(fd);
	return (result);
}

int	validate_map(t_MapData **map_data)
{
	char	**map_data_array;
	int		x;
	int		y;

	if (!find_player_position((*map_data)->map_array, &x, &y))
		return (1);
	map_data_array = copy_map(map_data);
	(*map_data)->c_count = count_collectibles(map_data_array);
	if (map_walls(map_data_array) || map_elements(map_data_array))
	{
		free_map(map_data_array);
		return (1);
	}
	flood_fill(map_data_array, x, y, map_data);
	if ((*map_data)->c_count != 0 || (*map_data)->exit_flag == 0)
	{
		free_map(map_data_array);
		return (1);
	}
	free_map(map_data_array);
	return (0);
}

int	get_map_height(char *path)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (height);
}

int	validate_path(int argc, char *argv[], t_MapData **mapdata)
{
	int	i;

	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 35);
		return (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
		{
			if (argv[1][i + 1] != 'b' || argv[1][i + 2] != 'e' || argv[1][i
				+ 3] != 'r' || argv[1][i + 4] != '\0')
			{
				free(*mapdata);
				write(2, "Error\nInvalid file extension\n", 30);
				return (1);
			}
		}
		i++;
	}
	(*mapdata)->path = argv[1];
	return (0);
}

int	main(int argc, char *argv[])
{
	t_MapData	*map_data;

	map_data = malloc(sizeof(t_MapData));
	if (validate_path(argc, argv, &map_data) || map_rectangle(argv[1],
			&map_data) || check_invalid_newline(argv[1]))
		return (0);
	map_data->map_array = readmap(argv[1]);
	if (!map_data->map_array || check_invalid_characters(map_data->map_array)
		|| validate_map(&map_data))
	{
		free_map(map_data->map_array);
		free(map_data);
		write(2, "Error\nInvalid map\n", 19);
		return (0);
	}
	if (init_mlx(&map_data))
		return (0);
	draw_window(&map_data);
	mlx_key_hook(map_data->win, key_hook, &map_data);
	mlx_hook(map_data->win, 17, 0, close_window, &map_data);
	mlx_loop(map_data->mlx);
	return (0);
}
