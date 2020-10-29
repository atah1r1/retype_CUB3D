/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:56:09 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 12:58:10 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		read_line(char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0 && read_resolution(line) == ERROR)
		return (set_error("res error!"));
	else if (ft_strncmp(line, "NO", 2) == 0
		&& read_texture(line, &texture[0]) == ERROR)
		return (set_error("no error!"));
	else if (ft_strncmp(line, "SO", 2) == 0
		&& read_texture(line, &texture[1]) == ERROR)
		return (set_error("no error!"));
	else if (ft_strncmp(line, "WE", 2) == 0
		&& read_texture(line, &texture[3]) == ERROR)
		return (set_error("no error!"));
	else if (ft_strncmp(line, "EA", 2) == 0
		&& read_texture(line, &texture[2]) == ERROR)
		return (set_error("no error!"));
	else if (ft_strncmp(line, "S ", 2) == 0
		&& read_texture(line, &texture[4]) == ERROR)
		return (set_error("s error!"));
	else if (ft_strncmp(line, "F ", 2) == 0
		&& read_color(line, &(g_data->floor)) == ERROR)
		return (set_error("f error"));
	else if (ft_strncmp(line, "C ", 2) == 0
		&& read_color(line, &(g_data->ceil)) == ERROR)
		return (set_error("c error"));
	else if ((line[0] == '1' || line[0] == ' ') && read_map_row(line) == ERROR)
		return (set_error("map error"));
	return (SUCCESS);
}
