/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:44:01 by atahiri           #+#    #+#             */
/*   Updated: 2020/11/19 23:55:07 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	initialize_player()
{
	g_player->x = (20 * TILE_SIZE) / 2;
	g_player->y = (g_data->map_height * TILE_SIZE) / 2;
	g_player->turn_d = 0;
	g_player->walk_d = 0;
	g_player->turn_spd = 1 * RAD;
	g_player->walk_spd = TILE_SIZE / 10;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error in arguments...", 22);
		return (0);
	}
	if (handle_argv(argv[1]) == 2)
	{
		write(1, "Invalid / not Found Map file ...", 32);
		return (0);
	}
	if (!(g_data = ((t_struct*)malloc(sizeof(t_struct)))))
		return (0);
	if (!(g_player = (t_player*)malloc(sizeof(t_player))))
		return (0);
	ft_read(argv[1]);
	// printf("NO = %s\n", g_texture[0].path);
    // printf("SO = %s\n", g_texture[1].path);
    // printf("WE = %s\n", g_texture[2].path);
    // printf("EA = %s\n", g_texture[3].path);
	// printf("SS = %s\n", g_texture[4].path);
	initialize_player();
	if (!(g_data->ptr = mlx_init()))
		return (0);
	if (!(g_data->win = mlx_new_window(g_data->ptr, g_data->w_width, g_data->w_height, "Cub3d By atah1r1")))
		return (0);
	if (!(g_data->image3d = mlx_new_image(g_data->ptr, g_data->w_width, g_data->w_height)))
		return (0);
	if (!(g_data->matrix3d = (int*)mlx_get_data_addr(g_data->image3d, &g_data->bits_per_pixel, &g_data->size_line, &g_data->endian)))
		return (0);
	handle_texture();
	mlx_hook(g_data->win, 2, 0, keypress, g_player);
	mlx_hook(g_data->win, 3, 0, keyrelease, g_data);
	mlx_loop_hook(g_data->ptr, loop, g_data);
	mlx_loop(g_data->ptr);
	return (0);
}
