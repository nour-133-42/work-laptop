/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:36:45 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/01 20:50:18 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_MapData **mapdata)
{
	char	**map;
	int		px;
	int		py;

	map = (*mapdata)->map_array;
	px = (*mapdata)->px;
	py = (*mapdata)->py;
	if (map[py][px + 1] == '0')
		swap(&map[py][px + 1], &map[py][px]);
	else if (map[py][px + 1] == 'C')
	{
		swap(&map[py][px + 1], &map[py][px]);
		map[py][px] = '0';
		(*mapdata)->current_collectible_count++;
	}
	else if (map[py][px + 1] == 'E')
	{
		swap(&map[py][px + 1], &map[py][px]);
		map[py][px] = '0';
		if ((*mapdata)->current_collectible_count == (*mapdata)->collectible_count)
			close_window(mapdata);
	}
	if ((map[py][px + 1] == '0' || map[py][px + 1] == 'C' || map[py][px
			+ 1] == 'E'))
		update_map(mapdata, map, 2);
}

void	move_left(t_MapData **mapdata)
{
	char	**map;
	int		px;
	int		py;

	map = (*mapdata)->map_array;
	px = (*mapdata)->px;
	py = (*mapdata)->py;
	if (map[py][px - 1] == '0')
		swap(&map[py][px - 1], &map[py][px]);
	else if (map[py][px - 1] == 'C')
	{
		swap(&map[py][px - 1], &map[py][px]);
		map[py][px] = '0';
		(*mapdata)->current_collectible_count++;
	}
	else if (map[py][px - 1] == 'E')
	{
		swap(&map[py][px - 1], &map[py][px]);
		map[py][px] = '0';
		if ((*mapdata)->current_collectible_count == (*mapdata)->collectible_count)
			close_window(mapdata);
	}
	if ((map[py][px - 1] == '0' || map[py][px - 1] == 'C' || map[py][px
			- 1] == 'E'))
		update_map(mapdata, map, 2);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	update_map(t_MapData **mapdata, char **map, int t)
{
	int	px;
	int	py;

	px = (*mapdata)->px;
	py = (*mapdata)->py;
	(*mapdata)->map_array = map;
	if ((py == (*mapdata)->ey || px == (*mapdata)->ex))
		map[py][px] = 'E';
	if (t == 1)
		(*mapdata)->py++;
	else if (t == 2)
		(*mapdata)->py--;
	else if (t == 3)
		(*mapdata)->px++;
	else if (t == 4)
		(*mapdata)->px--;
}
