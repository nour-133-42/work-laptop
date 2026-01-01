/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:32:23 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/01 20:57:20 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	free_all(t_MapData **mapdata)
{
	int		i;
	char	**map;

	map = (*mapdata)->map_array;
	i = 0;
	if ((*mapdata)->win && (*mapdata)->Mlx)
		mlx_destroy_window((*mapdata)->Mlx, (*mapdata)->win);
	destroy_image(mapdata);
	if ((*mapdata)->Mlx)
	{
		mlx_destroy_display((*mapdata)->Mlx);
		free((*mapdata)->Mlx);
	}
	free_map((*mapdata)->map_array);
	free(*mapdata);
	return (1);
}

int	find_exit_position(char **map_array, int *ex, int *ey)
{
	int	i;
	int	j;

	*ex = 0;
	*ey = 0;
	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == 'E')
			{
				*ex = j;
				*ey = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	move_down(t_MapData **mapdata)
{
	char	**map;
	int		px;
	int		py;

	map = (*mapdata)->map_array;
	px = (*mapdata)->px;
	py = (*mapdata)->py;
	if (map[py + 1][px] == '0')
		swap(&map[py + 1][px], &map[py][px]);
	else if (map[py + 1][px] == 'C')
	{
		swap(&map[py + 1][px], &map[py][px]);
		map[py][px] = '0';
		(*mapdata)->current_collectible_count++;
	}
	else if (map[py + 1][px] == 'E')
	{
		swap(&map[py + 1][px], &map[py][px]);
		map[py][px] = '0';
		if ((*mapdata)->current_collectible_count == (*mapdata)->collectible_count)
			close_window(mapdata);
	}
	if ((map[py + 1][px] == '0' || map[py + 1][px] == 'C' || map[py
			+ 1][px] == 'E'))
		update_map(mapdata, map, 2);
}

void	move_up(t_MapData **mapdata)
{
	char	**map;
	int		px;
	int		py;

	map = (*mapdata)->map_array;
	px = (*mapdata)->px;
	py = (*mapdata)->py;
	if (map[py - 1][px] == '0')
		swap(&map[py - 1][px], &map[py][px]);
	else if (map[py - 1][px] == 'C')
	{
		swap(&map[py - 1][px], &map[py][px]);
		map[py][px] = '0';
		(*mapdata)->current_collectible_count++;
	}
	else if (map[py - 1][px] == 'E')
	{
		swap(&map[py - 1][px], &map[py][px]);
		map[py][px] = '0';
		if ((*mapdata)->current_collectible_count == (*mapdata)->collectible_count)
			close_window(mapdata);
	}
	if ((map[py - 1][px] == '0' || map[py - 1][px] == 'C' || map[py
			- 1][px] == 'E'))
		update_map(mapdata, map, 2);
}
