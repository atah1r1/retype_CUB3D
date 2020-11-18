/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:54:06 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/18 18:35:33 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	handle_rays(int s_id)
{
	g_ray[s_id].hit_ver = 0;
	g_ray[s_id].ray_angle = normalize_angle(g_ray[s_id].ray_angle);
	g_ray[s_id].wall_down = g_ray[s_id].ray_angle > 0 &&
								g_ray[s_id].ray_angle < M_PI;
	g_ray[s_id].wall_up = !g_ray[s_id].wall_down;
	g_ray[s_id].wall_right = g_ray[s_id].ray_angle < 0.5 * M_PI ||
								g_ray[s_id].ray_angle > 1.5 * M_PI;
	g_ray[s_id].wall_left = !g_ray[s_id].wall_right;
	find_horz_wall_hint(s_id);
}

void	find_horz_wall_hint(int s_id)
{
	int		found_h_wall;
	float	x_intercept;
	float	y_intercept;
	float	xstep;
	float	ystep;

	found_h_wall = 0;
	y_intercept = floor(g_player->y / TILE_SIZE) * TILE_SIZE;
	y_intercept += g_ray[s_id].wall_up ? TILE_SIZE : 0;
	x_intercept = g_player->x + (y_intercept - g_player->y) /
		tan(g_ray[s_id].ray_angle);
	ystep = TILE_SIZE;
	ystep *= g_ray[s_id].wall_up ? -1 : 1;
	xstep = TILE_SIZE / tan(g_ray[s_id].ray_angle);
	xstep *= (g_ray[s_id].wall_left && xstep > 0) ? -1 : 1;
	xstep *= (g_ray[s_id].wall_right && xstep < 0) ? -1 : 1;
	find_horz_distance(x_intercept, y_intercept, found_h_wall, s_id, xstep, ystep);
}

void	find_horz_distance(float x_intercept, float y_intercept, int found_h_wall, int s_id, float xstep, float ystep)
{
	float	next_horz_x;
	float	next_horz_y;
	float	horz_hit_dist;
	float	wall_horz_x;
	float	wall_horz_y;

	next_horz_x = x_intercept;
	next_horz_y = y_intercept;
	wall_horz_x = 0;
	wall_horz_y = 0;
	while (next_horz_x >= 0 && next_horz_x <= (g_data->map->len * TILE_SIZE) &&
			next_horz_y >= 0 && next_horz_y <= (g_data->map_height - 1) * TILE_SIZE)
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
	horz_hit_dist = (found_h_wall)
	? distance_between_points(g_player->x, g_player->y, wall_horz_x, wall_horz_y)
	: INT_MAXX;
	find_vert_wall_hint(xstep, ystep, x_intercept, y_intercept, s_id);
}

void	find_vert_wall_hint(float xstep, float ystep, float x_intercept, float y_intercept, int s_id)
{
	int		found_vert_wall;
	float	next_vert_x;
	float	next_vert_y;

	found_vert_wall = 0;
	x_intercept = floor(g_player->x / TILE_SIZE) * TILE_SIZE;
	x_intercept += g_ray[s_id].wall_right ? TILE_SIZE : 0;
	y_intercept = g_player->y + (x_intercept - g_player->x) * tan(g_ray[s_id].ray_angle);
	xstep = TILE_SIZE;
	xstep *= g_ray[s_id].wall_left ? -1 : 1;
	ystep = TILE_SIZE * tan(g_ray[s_id].ray_angle);
	ystep *= (g_ray[s_id].wall_up && ystep > 0) ? -1 : 1;
	ystep *= (g_ray[s_id].wall_down && ystep < 0) ? -1 : 1;
	next_vert_x = x_intercept;
	next_vert_y = y_intercept;
	find_vert_distance(next_vert_x, next_vert_y, found_vert_wall, xstep, ystep, s_id);
}

void	find_vert_distance(float next_vert_x, float next_vert_y, int found_vert_wall, float xstep, float ystep, int s_id)
{
	float	wall_vert_hit_x;
	float	wall_vert_hit_y;
	float	vert_hit_distance;

	while (next_vert_x >= 0 && next_vert_x <= (g_data->map->len * TILE_SIZE) &&
			next_vert_y >= 0 && next_vert_y <= (g_data->map_height - 1) * TILE_SIZE)
	{
		if (wall_check(g_ray[s_id].wall_left ? next_vert_x - 1 : next_vert_x, next_vert_y))
		{
			found_vert_wall = 1;
			wall_vert_hit_x = next_vert_x;
			wall_vert_hit_y = next_vert_y;
			vert_hit_distance = distance_between_points(g_player->x, g_player->y, wall_vert_hit_x, wall_vert_hit_y);
			break ;
		}
		else
		{
			next_vert_x += xstep;
			next_vert_y += ystep;
		}
	}
	vert_hit_distance = (found_vert_wall)
	? distance_between_points(g_player->x, g_player->y, wall_vert_hit_x, wall_vert_hit_y)
	: INT_MAXX;
}
