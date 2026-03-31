/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 18:14:51 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 18:15:09 by eteofilo         ###   ########.fr       */
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

    // Desenha os tiles do mapa
    i = 0;
    while (i < data->map_size[1])
    {
        j = 0;
        while (j < data->map_size[0])
        {
            if (data->map[i][j] == 1)
                color = 0xFFFFFF;  // parede
            else if (data->map[i][j] == 0)
                color = 0x555555;  // chão
            else
                color = 0x000000;  // vazio/-1

            int dy = 0;
            while (dy < tile - 1)  // -1 pra borda
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

    // Player
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

    // Seta de direção
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
