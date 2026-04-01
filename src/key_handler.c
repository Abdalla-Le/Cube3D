/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:04:24 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 20:59:16 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move_forward_back(t_data *data, double margin,
		double move_speed, int direction)
{
	double	dx;
	double	dy;
	int		check_x;
	int		check_y;

	dx = data->player.dir_x * direction;
	dy = data->player.dir_y * direction;
	check_x = (int)(data->player.pos_x + dx * margin);
	if (!is_wall(data, check_x, (int)(data->player.pos_y)))
		data->player.pos_x += dx * move_speed;
	check_y = (int)(data->player.pos_y + dy * margin);
	if (!is_wall(data, (int)(data->player.pos_x), check_y))
		data->player.pos_y += dy * move_speed;
}

static void	move_strafe(t_data *data, double margin,
		double move_speed, int direction)
{
	double	side_x;
	double	side_y;
	int		check_x;
	int		check_y;

	side_x = data->player.dir_y * direction;
	side_y = -data->player.dir_x * direction;
	check_x = (int)(data->player.pos_x + side_x * margin);
	if (!is_wall(data, check_x, (int)(data->player.pos_y)))
		data->player.pos_x += side_x * move_speed;
	check_y = (int)(data->player.pos_y + side_y * margin);
	if (!is_wall(data, (int)(data->player.pos_x), check_y))
		data->player.pos_y += side_y * move_speed;
}

static void	rotate_player(t_data *data, double rot_speed, int direction)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = rot_speed * direction;
	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(angle)
		- data->player.dir_y * sin(angle);
	data->player.dir_y = old_dir_x * sin(angle)
		+ data->player.dir_y * cos(angle);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(angle)
		- data->player.plane_y * sin(angle);
	data->player.plane_y = old_plane_x * sin(angle)
		+ data->player.plane_y * cos(angle);
}

int	key_handler(int keycode, t_data *data)
{
	double	move_speed;
	double	rot_speed;
	double	margin;

	move_speed = 0.5;
	rot_speed = 0.08;
	margin = 1.0;
	if (keycode == KEY_ESC)
		close_window(data);
	if (keycode == KEY_W)
		move_forward_back(data, margin, move_speed, 1);
	if (keycode == KEY_S)
		move_forward_back(data, margin, move_speed, -1);
	if (keycode == KEY_A)
		move_strafe(data, margin, move_speed, -1);
	if (keycode == KEY_D)
		move_strafe(data, margin, move_speed, 1);
	if (keycode == KEY_RIGHT)
		rotate_player(data, rot_speed, -1);
	if (keycode == KEY_LEFT)
		rotate_player(data, rot_speed, 1);
	return (0);
}
