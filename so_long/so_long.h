/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:37:55 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/01 20:56:11 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_MapData
{
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		current_collectible_count;
	int		px;
	int		py;
	int		ex;
	int		ey;
	char	**map_array;
	char	*path;
	// int	moves;
	void	*Mlx;
	void	*win;
	void	*Floor_image;
	void	*Exit_image;
	void	*Collectable_image;
	void	*Player_image;
	void	*Wall_image;
}			t_MapData;

int			line_length(char *path);
int			free_all(t_MapData **mapdata);
int			map_rectangle(char *path);
int			map_walls(char **map_array);
int			map_elements(char **map_array);
int			get_map_height(char *path);
int			find_player_position(char **map_array, int *player_x,
				int *player_y);
int			flood_fill(char **map_array, int x, int y, int *collectible_count);
char		**readmap(char *path);
int			count_collectibles(char **map_array);
char		**copy_map(t_MapData **map_data);
int			check_after_fill(char **map);
int			check_invalid_newline(char *path);
int			close_window(t_MapData **param);
int			key_hook(int keycode, t_MapData **param);
void		destroy_image(t_MapData **mapdata);
void		draw_window(t_MapData **mapdata);
int			init_mlx(t_MapData **mapdata);
int			find_exit_position(char **map_array, int *ex, int *ey);
void		move_up(t_MapData **mapdata);
void		move_down(t_MapData **mapdata);
void		move_right(t_MapData **mapdata);
void		move_left(t_MapData **mapdata);
void		swap(char *a, char *b);
void		free_map(char **map);
void		update_map(t_MapData **mapdata, char **map, int t);
