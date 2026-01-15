/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:32:23 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/07 12:02:11 by nalshmai         ###   ########.fr       */
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
	if ((*mapdata)->win && (*mapdata)->mlx)
		mlx_destroy_window((*mapdata)->mlx, (*mapdata)->win);
	destroy_image(mapdata);
	if ((*mapdata)->mlx)
	{
		mlx_destroy_display((*mapdata)->mlx);
		free((*mapdata)->mlx);
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

void	move_down(t_MapData **md)
{
	char	**map;
	char	target;

	map = (*md)->map_array;
	target = map[(*md)->py + 1][(*md)->px];
	if (target == '1')
		return ;
	map[(*md)->py][(*md)->px] = '0';
	if (target == '0')
		map[(*md)->py + 1][(*md)->px] = 'P';
	else if (target == 'C')
	{
		map[(*md)->py + 1][(*md)->px] = 'P';
		(*md)->current_c_count++;
	}
	else if (target == 'E')
	{
		if ((*md)->c_count == (*md)->current_c_count)
			close_window(md);
		map[(*md)->py + 1][(*md)->px] = 'P';
	}
	update_map(md, map, 1);
}

void	move_up(t_MapData **md)
{
	char	**map;
	char	target;

	map = (*md)->map_array;
	target = map[(*md)->py - 1][(*md)->px];
	if (target == '1')
		return ;
	map[(*md)->py][(*md)->px] = '0';
	if (target == '0')
		map[(*md)->py - 1][(*md)->px] = 'P';
	else if (target == 'C')
	{
		map[(*md)->py - 1][(*md)->px] = 'P';
		(*md)->current_c_count++;
	}
	else if (target == 'E')
	{
		if ((*md)->c_count == (*md)->current_c_count)
			close_window(md);
		map[(*md)->py - 1][(*md)->px] = 'P';
	}
	update_map(md, map, 2);
}
