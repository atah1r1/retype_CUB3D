/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:50:30 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 11:04:23 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int     handle_argv(char *str)
{
    int len;

    len = ft_strlen(str);
    if (ft_strncmp(str + (len - 4), ".cub", 4))
        return (ERROR);
    return (SUCCESS);
}