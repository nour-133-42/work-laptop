/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:14:49 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/29 16:24:05 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**readmap(char *path)
{
	char	*line;
	char	**result;
	int		i;
	int		fd;

	result = malloc(sizeof(char **) * (get_map_height(path) + 1));
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCould not open file\n", 27);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line && ft_strlen(line))
	{
		result[i++] = line;
		line = get_next_line(fd);
	}
	result[i] = NULL;
	close(fd);
	free(line);
	return (result);
}

int	validate_map(t_MapData **map_data)
{
	char	**map_data_array;
	int		x;
	int		y;
	int		collectible_count;

	if (!find_player_position((*map_data)->map_array, &x, &y))
		return (1);
	map_data_array = copy_map(map_data);
	(*map_data)->collectible_count = count_collectibles(map_data_array);
	collectible_count = (*map_data)->collectible_count;
	if (map_walls(map_data_array) || map_elements(map_data_array))
		return (1);
	flood_fill(map_data_array, x, y, &collectible_count);
	if (/*collectible_count != ||*/ !check_after_fill(map_data_array))
	{
		write(2, "Error\nthar is no valid path to Exit", 36);
		return (1);
	}
	return (0);
}

int	get_map_height(char *path)
{
	int		fd;
	char	*line;
	int		height;
	int		line_len;

	height = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	line_len = ft_strlen(line);
	while (line && line_len)
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
	if (validate_path(argc, argv, &map_data) || map_rectangle(argv[1]) || check_invalid_newline(argv[1]))
		return (0);
	map_data->map_array = readmap(argv[1]);
	if (!map_data->map_array || validate_map(&map_data) )
	{
		write(2, "Error\nInvalid map\n", 19);
		return (0);
	}
	return (0);
}
