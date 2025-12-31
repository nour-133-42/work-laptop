/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:09:25 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/31 19:59:28 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_in_windows(int i, int j, t_MapData **mapdata)
{
	char	**map;

	map = (*mapdata)->map_array;
	if (map[i][j] == '1')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Wall_image, i * 32, j * 32);
	else if (map[i][j] == '0')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Floor_image, i * 32, j * 32);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Player_image, i * 32, j * 32);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Exit_image, i * 32, j * 32);
	else if (map[i][j] == 'C')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Collectable_image, i * 32, j * 32);
	else
	{
	}
}

int	draw_window(t_MapData **mapdata)
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

int	key_hook(int keycode, void *param)
{
	if (keycode == 53) // ESC
		exit(0);
	if (keycode == 13) // W
		move_up();
	if (keycode == 0) // A
		move_left();
	if (keycode == 1) // S
		move_right();
	if (keycode == 2) // D
		move_down();
	return (0);
}

int	close_window(void *param)
{
	exit(0);
	return (0);
}
