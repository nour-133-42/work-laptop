/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:49:23 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/24 17:49:24 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char    **copy_map(t_MapData **map_data)
{
    int i;
    int line_len;
    char **copy_map;

    i = 0;
    line_len = line_length((*map_data)->path);
    copy_map = malloc(get_map_height((*map_data)->path) + 1);
    while((*map_data)->map_array[i])
    {
        copy_map[i] = malloc(line_len + 1);
        copy_map[i] = (*map_data)->map_array[i];
        i++;
    }
    return (copy_map);
}

int check_after_fill(char **map)
{
    int i;
    int j;
    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'C' || map[i][j] == 'E')
            {
                return (1);
            }
        }
    }
    return(0);
}
