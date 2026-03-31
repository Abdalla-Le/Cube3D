/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:04:24 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 15:38:55 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static double	offset_by_dir(double dir, double margin)
{
	if (dir >= 0)
		return (margin);
	return (-margin);
}

static void	key_w(t_data *data, double margin, double move_speed)
{
	double	next_x;
	double	next_y;

	next_x = data->player.pos_x + data->player.dir_x * move_speed;
	next_y = data->player.pos_y + data->player.dir_y * move_speed;
	if (!is_wall(data, (int)(next_x + offset_by_dir(data->player.dir_x, margin)),
			(int)(data->player.pos_y)))
		data->player.pos_x = next_x;
	if (!is_wall(data, (int)(data->player.pos_x),
			(int)(next_y + offset_by_dir(data->player.dir_y, margin))))
		data->player.pos_y = next_y;
}

static void	key_s(t_data *data, double margin, double move_speed)
{
	double	next_x;
	double	next_y;

	next_x = data->player.pos_x - data->player.dir_x * move_speed;
	next_y = data->player.pos_y - data->player.dir_y * move_speed;
	if (!is_wall(data, (int)(next_x - offset_by_dir(data->player.dir_x, margin)),
			(int)(data->player.pos_y)))
		data->player.pos_x = next_x;
	if (!is_wall(data, (int)(data->player.pos_x),
			(int)(next_y - offset_by_dir(data->player.dir_y, margin))))
		data->player.pos_y = next_y;
}

static void	key_right(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(-rot_speed)
		- data->player.dir_y * sin(-rot_speed);
	data->player.dir_y = old_dir_x * sin(-rot_speed)
		+ data->player.dir_y * cos(-rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-rot_speed)
		- data->player.plane_y * sin(-rot_speed);
	data->player.plane_y = old_plane_x * sin(-rot_speed)
		+ data->player.plane_y * cos(-rot_speed);
}

static void	key_left(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rot_speed)
		- data->player.dir_y * sin(rot_speed);
	data->player.dir_y = old_dir_x * sin(rot_speed)
		+ data->player.dir_y * cos(rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot_speed)
		- data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed)
		+ data->player.plane_y * cos(rot_speed);
}

int	key_handler(int keycode, t_data *data)
{
	double	move_speed;
	double	rot_speed;
	double	margin;

	move_speed = 0.12;
	rot_speed = 0.08;
	margin = 0.18;
	if (keycode == KEY_ESC)
		close_window(data);
	if (keycode == KEY_W)
		key_w(data, margin, move_speed);
	if (keycode == KEY_S)
		key_s(data, margin, move_speed);
	if (keycode == KEY_RIGHT)
		key_right(data, rot_speed);
	if (keycode == KEY_LEFT)
		key_left(data, rot_speed);
	return (0);
}
