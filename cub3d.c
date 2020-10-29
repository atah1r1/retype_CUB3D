/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:44:01 by atahiri           #+#    #+#             */
/*   Updated: 2020/10/29 11:16:57 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int     main(int argc, char **argv)
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
    //ft_read(argv[1]);
    return (0);
}