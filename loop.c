/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:42:57 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 13:52:49 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	loop(void)
{
	move_player();
	cast_rays();
	three_d();
	mlx_put_image_to_window(g_data->ptr, g_data->win, g_data->image3d, 0, 0);
	return (0);
}
