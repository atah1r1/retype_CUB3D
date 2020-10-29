/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:41:49 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 13:42:13 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int		keypress(int keycode)
{
	if (keycode == FORWARD)
		g_player->walk_d = 1;
	else if (keycode == BACKWARD)
		g_player->walk_d = -1;
	if (keycode == RIGHT)
		g_player->turn_d = 1;
	else if (keycode == LEFT)
		g_player->turn_d = -1;
	return (0);
}

int		keyrelease(int keycode)
{
	if (keycode == FORWARD)
		g_player->walk_d = 0;
	if (keycode == BACKWARD)
		g_player->walk_d = 0;
	if (keycode == RIGHT)
		g_player->turn_d = 0;
	if (keycode == LEFT)
		g_player->turn_d = 0;
	return (0);
}
