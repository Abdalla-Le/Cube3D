/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:14:51 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 20:15:31 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    draw_minimap(t_data *data)
{
    int tile = 6;
    int offset_x = 10;
    int offset_y = 10;
    int i;
    int j;
    int color;

    printf("minimap: map_size[0]=%d map_size[1]=%d\n",
        data->map_size[0], data->map_size[1]);
    printf("map ptr: %p\n", (void *)data->map);
    i = 0;
    while (i < data->map_size[1])
    {
        j = 0;
        while (j < data->map_size[0])
        {
            if (data->map[i][j] == 1)
                color = 0xFFFFFF;
            else if (data->map[i][j] == 0)
                color = 0x555555;
            else
                color = 0x000000;

            int dy = 0;
            while (dy < tile - 1)
            {
                int dx = 0;
                while (dx < tile - 1)
                {
                    my_mlx_pixel_put(data,
                        offset_x + j * tile + dx,
                        offset_y + i * tile + dy,
                        color);
                    dx++;
                }
                dy++;
            }
            j++;
        }
        i++;
    }

    int px = offset_x + (int)(data->player.pos_y * tile);
    int py = offset_y + (int)(data->player.pos_x * tile);
    int dy = -2;
    while (dy <= 2)
    {
        int dx = -2;
        while (dx <= 2)
        {
            my_mlx_pixel_put(data, px + dx, py + dy, 0xFF0000);
            dx++;
        }
        dy++;
    }

    int k = 0;
    while (k < tile * 2)
    {
        my_mlx_pixel_put(data,
            px + (int)(data->player.dir_y * k),
            py + (int)(data->player.dir_x * k),
            0xFF6600);
        k++;
    }
}
