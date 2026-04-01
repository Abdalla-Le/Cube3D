/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:14:36 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 21:14:37 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_tile(t_data *data, t_tile *t, int i, int j)
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
	while (dy < t->tile - 1)
	{
		dx = 0;
		while (dx < t->tile - 1)
		{
			my_mlx_pixel_put(data, t->offset_x + j * t->tile + dx,
				t->offset_y + i * t->tile + dy, color);
			dx++;
		}
		dy++;
	}
}

static void	draw_grid(t_data *data, t_tile *t)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_size[1])
	{
		j = 0;
		while (j < data->map_size[0])
		{
			draw_tile(data, t, i, j);
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
	t_tile	t;
	int		px;
	int		py;

	t.tile = 6;
	t.offset_x = 10;
	t.offset_y = 10;
	draw_grid(data, &t);
	px = t.offset_x + (int)(data->player.pos_y * t.tile);
	py = t.offset_y + (int)(data->player.pos_x * t.tile);
	draw_player(data, px, py);
	draw_direction(data, px, py, t.tile);
}
