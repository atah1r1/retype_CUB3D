/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:24:15 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/20 01:28:47 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int		wall_check(float x, float y)
{
	int	map_x;
	int map_y;

	map_x = floorf(x / TILE_SIZE);
	map_y = floorf(y / TILE_SIZE);
	if (g_data->map[map_y].row[map_x] == '1' ||
		g_data->map[map_y].row[map_x] == '2')
		return (1);
	return (0);
}
