/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:48:22 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/30 11:46:26 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	move_player(void)
{
	float nx;
	float ny;

	g_player->angle += (g_player->turn_d * g_player->turn_spd);
	g_player->angle = normalize_angle(g_player->angle);
	nx = g_player->x +
	(g_player->walk_d * g_player->walk_spd * cosf(g_player->angle));
	ny = g_player->y +
	(g_player->walk_d * g_player->walk_spd * sinf(g_player->angle));
	if (!(wall_check(nx, g_player->y)))
		g_player->x = nx;
	if (!(wall_check(g_player->x, ny)))
		g_player->y = ny;
}
