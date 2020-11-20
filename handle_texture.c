/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:20:44 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/20 01:29:48 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void    handle_texture()
{
    int i;

    i = 0;
    while (i < 4)
    {
        g_texture[i].img = mlx_xpm_file_to_image(g_data->ptr, g_texture[i].path, &g_texture[i].width, &g_texture[i].height);
        g_texture[i].color = (int*)mlx_get_data_addr(g_texture[i].img, &g_data->bits_per_pixel, &g_data->size_line, &g_data->endian);
        i++;
    }
}