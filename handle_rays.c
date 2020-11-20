/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:54:06 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/20 01:46:07 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	find_vert_distance(int s_id)
{
	while (g_hv.next_vert_x >= 0 &&
			g_hv.next_vert_x <= (20 * TILE_SIZE) &&
			g_hv.next_vert_y >= 0 &&
			g_hv.next_vert_y <= (g_data->map_height - 1) * TILE_SIZE)
	{
		if (wall_check(g_ray[s_id].wall_left ? g_hv.next_vert_x - 1 :
						g_hv.next_vert_x, g_hv.next_vert_y))
		{
			g_hv.found_v_wall = 1;
			g_hv.wall_vert_x = g_hv.next_vert_x;
			g_hv.wall_vert_y = g_hv.next_vert_y;
			g_hv.vert_hit_dist = dist_btw_p(g_player->x, g_player->y,
											g_hv.wall_vert_x, g_hv.wall_vert_y);
			break ;
		}
		else
		{
			g_hv.next_vert_x += g_hv.xstep;
			g_hv.next_vert_y += g_hv.ystep;
		}
	}
	g_hv.vert_hit_dist = (g_hv.found_v_wall)
	? dist_btw_p(g_player->x, g_player->y, g_hv.wall_vert_x, g_hv.wall_vert_y)
	: INT_MAXX;
}

void	find_vert_wall_hint(int s_id)
{
	g_hv.found_v_wall = 0;
	g_hv.x_intercept = floor(g_player->x / TILE_SIZE) * TILE_SIZE;
	g_hv.x_intercept += g_ray[s_id].wall_right ? TILE_SIZE : 0;
	g_hv.y_intercept = g_player->y + (g_hv.x_intercept - g_player->x) *
		tan(g_ray[s_id].ray_angle);
	g_hv.xstep = TILE_SIZE;
	g_hv.xstep *= g_ray[s_id].wall_left ? -1 : 1;
	g_hv.ystep = TILE_SIZE * tan(g_ray[s_id].ray_angle);
	g_hv.ystep *= (g_ray[s_id].wall_up && g_hv.ystep > 0) ? -1 : 1;
	g_hv.ystep *= (g_ray[s_id].wall_down && g_hv.ystep < 0) ? -1 : 1;
	g_hv.next_vert_x = g_hv.x_intercept;
	g_hv.next_vert_y = g_hv.y_intercept;
	find_vert_distance(s_id);
}

void	find_horz_distance(int s_id)
{
	g_hv.next_horz_x = g_hv.x_intercept;
	g_hv.next_horz_y = g_hv.y_intercept;
	g_hv.wall_horz_x = 0;
	g_hv.wall_horz_y = 0;
	while (g_hv.next_horz_x >= 0 &&
			g_hv.next_horz_x <= (20 * TILE_SIZE) &&
			g_hv.next_horz_y >= 0 &&
			g_hv.next_horz_y <= (g_data->map_height - 1) * TILE_SIZE)
	{
		if (wall_check(g_hv.next_horz_x, g_ray[s_id].wall_up ?
						g_hv.next_horz_y - 1 : g_hv.next_horz_y))
		{
			g_hv.found_h_wall = 1;
			g_hv.wall_horz_x = g_hv.next_horz_x;
			g_hv.wall_horz_y = g_hv.next_horz_y;
			break ;
		}
		g_hv.next_horz_x += g_hv.xstep;
		g_hv.next_horz_y += g_hv.ystep;
	}
	g_hv.horz_hit_dist = (g_hv.found_h_wall)
	? dist_btw_p(g_player->x, g_player->y, g_hv.wall_horz_x, g_hv.wall_horz_y)
	: INT_MAXX;
	find_vert_wall_hint(s_id);
}

void	merge_distances(int s_id)
{
	g_ray[s_id].wall_hit_x = (g_hv.horz_hit_dist < g_hv.vert_hit_dist)
	? g_hv.wall_horz_x : g_hv.wall_vert_x;
	g_ray[s_id].wall_hit_y = (g_hv.horz_hit_dist < g_hv.vert_hit_dist)
	? g_hv.wall_horz_y : g_hv.wall_vert_y;
	g_ray[s_id].distance = (g_hv.horz_hit_dist < g_hv.vert_hit_dist)
	? g_hv.horz_hit_dist : g_hv.vert_hit_dist;
	g_ray[s_id].hit_ver = (g_hv.vert_hit_dist < g_hv.horz_hit_dist);
}

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
	g_hv.found_h_wall = 0;
	g_hv.y_intercept = floor(g_player->y / TILE_SIZE) * TILE_SIZE;
	g_hv.y_intercept += g_ray[s_id].wall_up ? TILE_SIZE : 0;
	g_hv.x_intercept = g_player->x + (g_hv.y_intercept - g_player->y) /
		tan(g_ray[s_id].ray_angle);
	g_hv.ystep = TILE_SIZE;
	g_hv.ystep *= g_ray[s_id].wall_up ? -1 : 1;
	g_hv.xstep = TILE_SIZE / tan(g_ray[s_id].ray_angle);
	g_hv.xstep *= (g_ray[s_id].wall_left && g_hv.xstep > 0) ? -1 : 1;
	g_hv.xstep *= (g_ray[s_id].wall_right && g_hv.xstep < 0) ? -1 : 1;
	find_horz_distance(s_id);
	merge_distances(s_id);
}