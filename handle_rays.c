/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:54:06 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/16 12:52:06 by atahiri          ###   ########.fr       */
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
	find_horz_wall_hint(x_intercept, y_intercept, xstep, ystep);
}

void	find_horz_wall_hint(float x_intercept, float y_intercept, float xstep, float ystep)
{
	int		found_h_wall;
	float	wall_horz_x;
	float	wall_horz_y;
	float	horz_hit_dist;

	found_h_wall = 0;
	wall_horz_x = 0;
	wall_horz_y = 0;
}
