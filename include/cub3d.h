/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:48:50 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 12:53:22 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include "get_next_line.h"

# define ESC 53
# define LEFT 0
# define RIGHT 2
# define FORWARD 13
# define BACKWARD 1
# define KEYUP 3
# define KEYDOWN 2
# define QUIT 17

# define TILE_SIZE 400
# define RAD (M_PI / 180)
# define FOV_ANGLE (60 * RAD)
# define WALL_STRIP_WIDTH 1
# define INT_MAXX 2147483647

# define ERROR 2
# define SUCCESS 0

typedef struct s_ray
{
    float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			hit_ver;
	int			wall_facing_up;
	int			wall_facing_down;
	int			wall_facing_left;
	int			wall_facing_right;
	int			wall_hit_content;
}				t_ray;

typedef struct s_player
{
    float x;
    float y;
    int turn_d;
    int walk_d;
    float angle;
    float walk_spd;
    float turn_spd;
}               t_player;

typedef struct s_texture
{
	void 	*img;
    int 	width;
    int 	height;
	char	*path;
	int		*color;
}			t_texture;

typedef	struct s_three_d
{
	float	cor_distance;
	float	dis_proj_pln;
	float	prj_wall_h;
	float	wall_tp_px;
	float	wall_bottom_px;
}				t_three_d;

typedef struct s_color
{
	int	r;
	int g;
	int b;
}				t_color;

typedef	struct s_map
{
	char	*row;
	int		len;
}				t_map;

typedef struct	s_struct
{
	int		w_width;
	int		w_height;
	void	*ptr;
	void	*win;
	void	*image;
	void	*image3d;
	int		*matrix;
	int		*matrix3d;
	int		map_height;
	t_color ceil;
	t_color floor;
	t_map	*map;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

}				t_struct;

t_struct	*g_data;
t_player	*g_player;
t_ray		*g_ray;
t_three_d	threed;
t_texture	texture[5];
int			g_read_nb;

int     handle_argv(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
