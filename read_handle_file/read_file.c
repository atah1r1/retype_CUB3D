/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:15:27 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 12:57:20 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		parts_number(char **parts)
{
	int i;

	i = 0;
	while (parts[i] != NULL)
		++i;
	return (i);
}

int		parts_free(char **parts)
{
	int i;

	i = 0;
	while (parts[i] != NULL)
		free(parts[i++]);
	free(parts);
	return (SUCCESS);
}

int		init_map(char *line)
{
	if (!(g_data->map = malloc(1 * sizeof(t_map))))
		return (ERROR);
	g_data->map[0].row = ft_strdup(line);
	g_data->map[0].len = ft_strlen(line);
	g_data->map_height = 1;
	free(line);
	return (SUCCESS);
}

int		send_player_position(char *row, int y)
{
	int i;

	i = 0;
	while (i < ft_strlen(row))
	{
		if (row[i] == 'N')
		{
			g_player->x = (i + 0.5F) * TILE_SIZE;
			g_player->y = (y + 0.5F) * TILE_SIZE;
		}
		i++;
	}
	return (0);
}

int		ft_read(char *file_name)
{
	int		fd;
	char	*line;

	g_read_nb = 0;
	g_data->map_height = 0;
	if (handle_argv(file_name) == ERROR)
		return (set_error("error"));
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (set_error("error 2"));
	while (get_next_line(fd, &line) > 0)
		if (read_line(line) == ERROR)
			return (ERROR);
	if (read_line(line) == ERROR)
		return (ERROR);
	close(fd);
	return (SUCCESS);
}
