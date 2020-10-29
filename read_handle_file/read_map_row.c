/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:57:00 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 12:58:07 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		read_map_row(char *line)
{
	int		i;
	t_map	*temp_map;

	i = 0;
	if (g_data->map == NULL)
		return (init_map(line));
	temp_map = g_data->map;
	if (!(g_data->map = (t_map *)malloc(sizeof(t_map) *
		(++g_data->map_height))))
		return (ERROR);
	while (g_data->map_height - 1 > i)
	{
		g_data->map[i] = temp_map[i];
		i++;
	}
	send_player_position(line, i);
	g_data->map[i].row = ft_strdup(line);
	g_data->map[i].len = ft_strlen(line);
	free(line);
	return (SUCCESS);
}
