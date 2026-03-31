/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:40:00 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 18:56:51 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	paint(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT / 2)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			my_mlx_pixel_put(data, j, i, data->real_map.ceil_color);
			j++;
		}
		i++;
	}
	i = W_HEIGHT / 2;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			my_mlx_pixel_put(data, j, i, data->real_map.floor_color);
			j++;
		}
		i++;
	}
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
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
