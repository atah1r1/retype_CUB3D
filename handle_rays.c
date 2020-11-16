/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:54:06 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/16 14:41:22 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	handle_rays(int s_id)
{
	float x_intercept;
	float y_intercept;
	float xstep;
	float ystep;

	g_ray[s_id].hit_ver = 0;
	g_ray[s_id].ray_angle = normalize_angle(g_ray[s_id].ray_angle);
	g_ray[s_id].wall_down = g_ray[s_id].ray_angle > 0 &&
								g_ray[s_id].ray_angle < M_PI;
	g_ray[s_id].wall_up = !g_ray[s_id].wall_down;
	g_ray[s_id].wall_right = g_ray[s_id].ray_angle < 0.5 * M_PI ||
								g_ray[s_id].ray_angle > 1.5 * M_PI;
	g_ray[s_id].wall_left = !g_ray[s_id].wall_right;
	find_horz_wall_hint(x_intercept, y_intercept, xstep, ystep, s_id);
}

void	find_horz_wall_hint(float x_intercept, float y_intercept, float xstep, float ystep, int s_id)
{
	int		found_h_wall;
	float	wall_horz_x;
	float	wall_horz_y;
	float	horz_hit_dist;

	found_h_wall = 0;
	wall_horz_x = 0;
	wall_horz_y = 0;
	y_intercept = floor(g_player->y / TILE_SIZE) * TILE_SIZE;
	y_intercept += g_ray[s_id].wall_up ? TILE_SIZE : 0;
	x_intercept = g_player->x + (y_intercept - g_player->y) / tan(g_ray[s_id].ray_angle);
	ystep = TILE_SIZE;
	ystep *= g_ray[s_id].wall_up ? -1 : 1;
	xstep = TILE_SIZE / tan(g_ray[s_id].ray_angle);
	xstep *= (g_ray[s_id].wall_left && xstep > 0) ? -1 : 1;
	xstep *= (g_ray[s_id].wall_right && xstep < 0) ? -1 : 1;
	find_horz_distance(x_intercept, y_intercept, wall_horz_x, wall_horz_y, found_h_wall, s_id, xstep, ystep);
}

void	find_horz_distance(float x_intercept, float y_intercept, float wall_horz_x, float wall_horz_y, int found_h_wall, int s_id, float xstep, float ystep)
{
	float	next_horz_x;
	float	next_horz_y;

	next_horz_x = x_intercept;
	next_horz_y = y_intercept;
	while (next_horz_x >= 0 && next_horz_x <= (g_data->map->len * TILE_SIZE) &&
			next_horz_y >= 0 && next_horz_y <= g_data->map_height * TILE_SIZE)
	{
		if (wall_check(next_horz_x, g_ray[s_id].wall_up ? next_horz_y - 1 : next_horz_y))
		{
			found_h_wall = 1;
			wall_horz_x = next_horz_x;
			wall_horz_y = next_horz_y;
			break ;
		}
		next_horz_x += xstep;
		next_horz_y += ystep;
	}
	// i stoped here
}
