/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:37:55 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/22 20:49:49 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_MapData
{
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	char	**map_array;
}			t_MapData;

int			line_length(char *path);
int			map_rectangle(char **map_array);
int			map_walls(char **map_array);
int			map_elements(char **map_array);
int			get_map_height(char *path);
