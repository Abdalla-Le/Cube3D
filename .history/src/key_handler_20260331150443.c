/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:04:24 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 15:04:43 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_handler(int keycode, t_data *data)
{
	double move_speed = 1.1;
	double rot_speed = 0.08;
	double margin = 0.2;

	if (keycode == 53)
		close_window(data);
	if (keycode == 13)
	{
		if (data->map[(int)(data->player.pos_x + data->player.dir_x * margin)]
			[(int)(data->player.pos_y)] == 0)
			data->player.pos_x += data->player.dir_x * move_speed;
		if (data->map[(int)(data->player.pos_x)]
			[(int)(data->player.pos_y + data->player.dir_y * margin)] == 0)
			data->player.pos_y += data->player.dir_y * move_speed;
	}
	if (keycode == 1)
	{
		if (data->map[(int)(data->player.pos_x - data->player.dir_x * margin)]
			[(int)(data->player.pos_y)] == 0)
			data->player.pos_x -= data->player.dir_x * move_speed;

		if (data->map[(int)(data->player.pos_x)]
			[(int)(data->player.pos_y - data->player.dir_y * margin)] == 0)
			data->player.pos_y -= data->player.dir_y * move_speed;
	}
	if (keycode == 124)
	{
		double old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(-rot_speed)
			- data->player.dir_y * sin(-rot_speed);
		data->player.dir_y = old_dir_x * sin(-rot_speed)
			+ data->player.dir_y * cos(-rot_speed);
		double old_plane_x = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(-rot_speed)
			- data->player.plane_y * sin(-rot_speed);
		data->player.plane_y = old_plane_x * sin(-rot_speed)
			+ data->player.plane_y * cos(-rot_speed);
	}
	if (keycode == 123)
	{
		double old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(rot_speed)
		- data->player.dir_y * sin(rot_speed);
		data->player.dir_y = old_dir_x * sin(rot_speed)
		+ data->player.dir_y * cos(rot_speed);
		double old_plane_x = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(rot_speed)
		- data->player.plane_y * sin(rot_speed);
		data->player.plane_y = old_plane_x * sin(rot_speed)
		+ data->player.plane_y * cos(rot_speed);
	}

	return (0);
}
