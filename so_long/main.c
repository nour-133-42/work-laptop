/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:14:49 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/15 21:13:22 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(char **map_array)
{
	if (map_rectangle(map_array) || map_walls(map_array)
		|| map_elements(map_array))
	{
		return (1);
	}
	return (0);
}

char	**readmap(char *path)
{
	char	*line;
	char	**result;
	int		i;
	int		fd;

	result = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCould not open file\n", 27);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		result[i++] = line;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (result);
}

int	validate_path(int argc, char *argv[])
{
	int	i;

	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 35);
		return (1);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
		{
			if (argv[1][i + 1] == 'b' && argv[1][i + 2] == 'e' && argv[1][i
				+ 3] == 'r' && argv[1][i + 4] == '\0')
				return (0);
			else
			{
				write(2, "Error\nInvalid file extension\n", 30);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_MapData	*map_data;

	if (validate_path(argc, argv))
		return (0);
	map_data->map_array = readmap(argv[1]);
	if (validate_map(map_data->map_array) || !map_data->map_array)
	{
		write(2, "Error\nInvalid map\n", 19);
		return (0);
	}
	return (0);
}
