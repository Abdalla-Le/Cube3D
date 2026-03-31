/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:40:00 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 14:40:29 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	raycasting_loop(t_data *data)
{
	int			x;
	t_raycast	raycast;
	t_img		*cur_tex;

	paint(data);
	x = 0;
	while (x < W_WIDTH)
	{
		set_raycast(x, &raycast, data);
		set_side(&raycast, data);
		set_step(&raycast, data);
		set_dda(&raycast, data);
		set_walls(&raycast);
		set_textures(x, &raycast, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
