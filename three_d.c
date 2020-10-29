/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:15:59 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 19:29:35 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "include/cub3d.h"

void		fill_threed(int i)
{
	g_threed.cor_distance = g_ray[i].distance * cosf(g_ray[i].ray_angle - g_player->angle);
	g_threed.dis_proj_pln = (g_data->w_width / 2) / tanf(FOV_ANGLE / 2);
	g_threed.prj_wall_h = (TILE_SIZE / (g_threed.cor_distance == 0 ? 0.1 : g_threed.cor_distance)) * g_threed.dis_proj_pln;
	g_threed.wall_tp_px = g_threed.wall_tp_px < 0 ? 0 : g_threed.wall_tp_px;
	g_threed.wall_bottom_px = (g_data->w_height / 2) + (g_threed.prj_wall_h / 2);
	g_threed.wall_bottom_px = g_threed.wall_bottom_px > g_data->w_height ? g_data->w_height : g_threed.wall_bottom_px;
}

void		three_d(void)
{
	int i;
	int j;
	int tx;
	int floor_color;
	int ciel_color;
	int textureOffsetX;

	i = 0;
	while(i < g_data->w_width)
	{
		j = 0;
		fill_threed(i);
		while (j < g_threed.wall_tp_px)
			g_data->matrix3d[(g_data->w_width * j++) + i] = ciel_color;
		if (g_ray[i].hit_ver)
			textureOffsetX = (int)g_ray[i].wall_hit_y % TILE_SIZE;
		else
			textureOffsetX = (int)g_ray[i].wall_hit_x % TILE_SIZE;
		textureOffsetX = textureOffsetX >= TILE_SIZE ? TILE_SIZE - 1 : textureOffsetX;
		
		
		
	}	
}