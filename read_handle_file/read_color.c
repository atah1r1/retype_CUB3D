/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:54:35 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 12:58:38 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		read_color(char *line, t_color *color)
{
	int		i;
	char	**parts;

	i = 0;
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	parts = ft_split(&line[i], ',');
	if (parts_number(parts) != 3)
		return (ERROR);
	color->r = atoi(parts[0]);
	color->g = atoi(parts[1]);
	color->b = atoi(parts[2]);
	++g_read_nb;
	free(line);
	return (parts_free(parts));
}
