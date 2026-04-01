/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:12:42 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 21:12:55 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_tile(t_data *data, int i, int j, int tile, int offset_x, int offset_y)
{
	int	color;
	int	dy;
	int	dx;

	if (data->map[i][j] == 1)
		color = 0xFFFFFF;
	else if (data->map[i][j] == 0)
		color = 0x555555;
	else
		color = 0x000000;
	dy = 0;
	while (dy < tile - 1)
	{
		dx = 0;
		while (dx < tile - 1)
		{
			my_mlx_pixel_put(data, offset_x + j * tile + dx,
				offset_y + i * tile + dy, color);
			dx++;
		}
		dy++;
	}
}

static void	draw_grid(t_data *data, int tile, int offset_x, int offset_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_size[1])
	{
		j = 0;
		while (j < data->map_size[0])
		{
			draw_tile(data, i, j, tile, offset_x, offset_y);
			j++;
		}
		i++;
	}
}

static void	draw_player(t_data *data, int px, int py)
{
	int	dy;
	int	dx;

	dy = -2;
	while (dy <= 2)
	{
		dx = -2;
		while (dx <= 2)
		{
			my_mlx_pixel_put(data, px + dx, py + dy, 0xFF0000);
			dx++;
		}
		dy++;
	}
}

static void	draw_direction(t_data *data, int px, int py, int tile)
{
	int	k;

	k = 0;
	while (k < tile * 2)
	{
		my_mlx_pixel_put(data,
			px + (int)(data->player.dir_y * k),
			py + (int)(data->player.dir_x * k),
			0xFF6600);
		k++;
	}
}

void	draw_minimap(t_data *data)
{
	int	tile;
	int	offset_x;
	int	offset_y;
	int	px;
	int	py;

	tile = 6;
	offset_x = 10;
	offset_y = 10;
	draw_grid(data, tile, offset_x, offset_y);
	px = offset_x + (int)(data->player.pos_y * tile);
	py = offset_y + (int)(data->player.pos_x * tile);
	draw_player(data, px, py);
	draw_direction(data, px, py, tile);
}
