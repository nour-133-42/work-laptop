/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:09:25 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/01 21:24:09 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_in_windows(int i, int j, t_MapData **mapdata)
{
	char	**map;

	map = (*mapdata)->map_array;
	if (map[i][j] == '1')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Wall_image, j * 32, i * 32);
	else if (map[i][j] == '0')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Floor_image, j * 32, i * 32);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Player_image, j * 32, i * 32);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Exit_image, j * 32, i * 32);
	else if (map[i][j] == 'C')
		mlx_put_image_to_window((*mapdata)->Mlx, (*mapdata)->win,
			(*mapdata)->Collectable_image, j * 32, i * 32);
}

void	destroy_image(t_MapData **mapdata)
{
	if ((*mapdata)->Collectable_image)
		mlx_destroy_image((*mapdata)->Mlx, (*mapdata)->Collectable_image);
	if ((*mapdata)->Exit_image)
		mlx_destroy_image((*mapdata)->Mlx, (*mapdata)->Exit_image);
	if ((*mapdata)->Floor_image)
		mlx_destroy_image((*mapdata)->Mlx, (*mapdata)->Floor_image);
	if ((*mapdata)->Player_image)
		mlx_destroy_image((*mapdata)->Mlx, (*mapdata)->Player_image);
	if ((*mapdata)->Wall_image)
		mlx_destroy_image((*mapdata)->Mlx, (*mapdata)->Wall_image);
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
	if (keycode == 65307) // ESC
	{
		free_all(param);
		exit(0);
	}
	if (keycode == 119) // W
		move_up(param);
	if (keycode == 97) // A
		move_left(param);
	if (keycode == 115) // S
		move_right(param);
	if (keycode == 100) // D
		move_down(param);
	return (0);
	mlx_clear_window((*param)->Mlx, (*param)->win);
	draw_window(param);
}

int	close_window(t_MapData **param)
{
	free_all(param);
	exit(0);
	return (0);
}
