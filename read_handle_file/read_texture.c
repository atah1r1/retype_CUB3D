/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:53:53 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 12:58:49 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		read_texture(char *line, t_texture *txt)
{
	int		i;
	char	**parts;

	i = 0;
	parts = ft_split(line, ' ');
	if (parts_number(parts) != 2)
		return (ERROR);
	txt->path = ft_strdup(parts[1]);
	++g_read_nb;
	free(line);
	return (parts_free(parts));
}
