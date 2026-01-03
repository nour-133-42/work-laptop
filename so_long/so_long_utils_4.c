/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:36:45 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/03 19:31:45 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	e;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		e = '-';
		write(fd, &e, 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	move_right(t_MapData **md)
{
	char	**map;
	char	target;

	map = (*md)->map_array;
	target = map[(*md)->py][(*md)->px + 1];
	if (target == '1')
		return ;
	map[(*md)->py][(*md)->px] = '0';
	if (target == '0')
		map[(*md)->py][(*md)->px + 1] = 'P';
	else if (target == 'C')
	{
		map[(*md)->py][(*md)->px + 1] = 'P';
		(*md)->current_c_count++;
	}
	else if (target == 'E')
	{
		if ((*md)->c_count == (*md)->current_c_count)
			close_window(md);
		map[(*md)->py][(*md)->px + 1] = 'P';
	}
	update_map(md, map, 3);
}

void	move_left(t_MapData **md)
{
	char	**map;
	char	target;

	map = (*md)->map_array;
	target = map[(*md)->py][(*md)->px - 1];
	if (target == '1')
		return ;
	map[(*md)->py][(*md)->px] = '0';
	if (target == '0')
		map[(*md)->py][(*md)->px - 1] = 'P';
	else if (target == 'C')
	{
		map[(*md)->py][(*md)->px - 1] = 'P';
		(*md)->current_c_count++;
	}
	else if (target == 'E')
	{
		if ((*md)->c_count == (*md)->current_c_count)
			close_window(md);
		map[(*md)->py][(*md)->px - 1] = 'P';
	}
	update_map(md, map, 4);
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
	if ((py == (*mapdata)->ey && px == (*mapdata)->ex))
		map[py][px] = 'E';
	if (t == 1)
		(*mapdata)->py++;
	else if (t == 2)
		(*mapdata)->py--;
	else if (t == 3)
		(*mapdata)->px++;
	else if (t == 4)
		(*mapdata)->px--;
	(*mapdata)->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr_fd((*mapdata)->moves, 1);
	write(1, "\n", 1);
	mlx_clear_window((*mapdata)->mlx, (*mapdata)->win);
	draw_window(mapdata);
}

int	count_empty_lines(t_MapData **md)
{
	int		count;
	int		i;
	char	**map;

	count = 0;
	map = (*md)->map_array;
	i = 0;
	while (map[i])
	{
		if (!ft_strlen(map[i]))
			count++;
		i++;
	}
	return (count);
}
