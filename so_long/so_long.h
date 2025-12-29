/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:37:55 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/24 18:00:08 by nalshmai         ###   ########.fr       */
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
	char	*path;
}			t_MapData;

int			line_length(char *path);
int			map_rectangle(char *path);
int			map_walls(char **map_array);
int			map_elements(char **map_array);
int			get_map_height(char *path);
int			find_player_position(char **map_array, int *player_x,
				int *player_y);
int			flood_fill(char **map_array, int x, int y, int *collectible_count);
char		**readmap(char *path);
int			count_collectibles(char **map_array);
char    **copy_map(t_MapData **map_data);
int check_after_fill(char **map);

