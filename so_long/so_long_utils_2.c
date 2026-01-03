/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:09:25 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/03 17:01:27 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_in_windows(int i, int j, t_MapData **mapdata)
{
	char	**map;

	map = (*mapdata)->map_array;
	if (map[i][j] == '1')
		mlx_put_image_to_window((*mapdata)->mlx, (*mapdata)->win,
			(*mapdata)->wall_image, j * 32, i * 32);
	else if (map[i][j] == '0')
		mlx_put_image_to_window((*mapdata)->mlx, (*mapdata)->win,
			(*mapdata)->floor_image, j * 32, i * 32);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window((*mapdata)->mlx, (*mapdata)->win,
			(*mapdata)->player_image, j * 32, i * 32);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window((*mapdata)->mlx, (*mapdata)->win,
			(*mapdata)->exit_image, j * 32, i * 32);
	else if (map[i][j] == 'C')
		mlx_put_image_to_window((*mapdata)->mlx, (*mapdata)->win,
			(*mapdata)->collectable_image, j * 32, i * 32);
}

void	destroy_image(t_MapData **mapdata)
{
	if ((*mapdata)->collectable_image)
		mlx_destroy_image((*mapdata)->mlx, (*mapdata)->collectable_image);
	if ((*mapdata)->exit_image)
		mlx_destroy_image((*mapdata)->mlx, (*mapdata)->exit_image);
	if ((*mapdata)->floor_image)
		mlx_destroy_image((*mapdata)->mlx, (*mapdata)->floor_image);
	if ((*mapdata)->player_image)
		mlx_destroy_image((*mapdata)->mlx, (*mapdata)->player_image);
	if ((*mapdata)->wall_image)
		mlx_destroy_image((*mapdata)->mlx, (*mapdata)->wall_image);
}

void	draw_window(t_MapData **mapdata)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (*mapdata)->map_array;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			put_image_in_windows(i, j, mapdata);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_MapData **param)
{
	if (keycode == 65307)
	{
		free_all(param);
		exit(0);
	}
	if (keycode == 119)
		move_up(param);
	if (keycode == 97)
		move_left(param);
	if (keycode == 100)
		move_right(param);
	if (keycode == 115)
		move_down(param);
	return (0);
}

int	close_window(t_MapData **param)
{
	free_all(param);
	exit(0);
	return (0);
}
