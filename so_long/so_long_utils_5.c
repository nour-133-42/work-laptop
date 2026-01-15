/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:06:29 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/04 21:19:34 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	first_init(t_MapData **md)
{
	(*md)->collectable_image = NULL;
	(*md)->exit_image = NULL;
	(*md)->floor_image = NULL;
	(*md)->player_image = NULL;
	(*md)->wall_image = NULL;
	(*md)->mlx = NULL;
	(*md)->win = NULL;
}
