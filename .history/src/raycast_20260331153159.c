/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_20260331153159.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:40:00 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 19:57:10 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void static	paint(t_data *data)
{
	for (int i = 0; i < W_HEIGHT / 2; i++)
		for (int j = 0; j < W_WIDTH; j++)
			my_mlx_pixel_put(data, j, i, data->real_map->ceil_color);
	for (int i = W_HEIGHT / 2; i < W_HEIGHT; i++)
		for (int j = 0; j < W_WIDTH; j++)
			my_mlx_pixel_put(data, j, i, data->real_map->floor_color);
}

int	raycasting_loop(t_data *data)
{
	int			x;
	t_raycast	raycast;

	paint(data);
	x = 0;
	while (x < W_WIDTH)
	{
		set_raycast(x, &raycast, data);
		set_side(&raycast, data);
		set_step(&raycast);
		set_dda(&raycast, data);
		set_walls(&raycast);
		set_textures(x, &raycast, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
