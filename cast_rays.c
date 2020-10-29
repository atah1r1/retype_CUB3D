/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:50:31 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 14:17:30 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float	normalize_angle(float angle)
{
	if (angle <= 0)
		angle += (2 * M_PI);
	else if (angle >= (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	cast_rays(void)
{
	int		strip_id;
	float	ray_angle;

	strip_id = 0;
	ray_angle = g_player->angle - (float)(FOV_ANGLE / 2);
	g_ray = (t_ray *)malloc(sizeof(t_ray) * g_data->w_width);
	while (strip_id < g_data->w_width)
	{
		g_ray[strip_id].ray_angle = normalize_angle(ray_angle);
		handle_rays(strip_id);
		ray_angle += (float)(FOV_ANGLE / g_data->w_width);
		strip_id++;
	}
	free(g_ray);
}
