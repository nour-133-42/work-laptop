/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalshmai <nalshmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:56:19 by nalshmai          #+#    #+#             */
/*   Updated: 2025/12/22 20:28:04 by nalshmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_length(char *path)
{
	int		fd;
	char	*line;
	int		length;

	length = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nCould not open file\n", 27);
		return (0);
	}
	line = get_next_line(fd);
	if (line)
	{
		while (line[length])
			length++;
	}
	free(line);
	close(fd);
	return (length);
}
