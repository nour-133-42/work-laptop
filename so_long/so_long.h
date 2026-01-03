/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:37:55 by nalshmai          #+#    #+#             */
/*   Updated: 2026/01/03 19:32:01 by nalshmai         ###   ########.fr       */
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
	int		c_count;
	int		current_c_count;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		exit_flag;
	char	**map_array;
	char	*path;
	int		moves;
	void	*mlx;
	void	*win;
	void	*floor_image;
	void	*exit_image;
	void	*collectable_image;
	void	*player_image;
	void	*wall_image;
}			t_MapData;

int			line_length(char *path);
void		ft_putnbr_fd(int n, int fd);
int			free_all(t_MapData **mapdata);
int			map_rectangle(char *path, t_MapData **mapdata);
int			map_walls(char **map_array);
int			map_elements(char **map_array);
int			get_map_height(char *path);
int			find_player_position(char **map_array, int *player_x,
				int *player_y);
void		flood_fill(char **map_array, int x, int y, t_MapData **md);
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
int			check_invalid_characters(char **map_array);
int			count_empty_lines(t_MapData **md);