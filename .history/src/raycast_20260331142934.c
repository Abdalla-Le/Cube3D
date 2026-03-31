/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:40:00 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 14:29:34 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_raycast(int x, t_raycast *raycast, t_data *data)
{
	double		camera_x;

	camera_x = 2 * x / (double)W_WIDTH - 1;
	raycast->ray_dir[0] = data->player.dir_x + data->player.plane_x * camera_x;
	raycast->ray_dir[1] = data->player.dir_y + data->player.plane_y * camera_x;
	raycast->map[0] = (int)data->player.pos_x;
	raycast->map[1] = (int)data->player.pos_y;
	raycast->delta_dist[0] = fabs(1 / raycast->ray_dir[0]);
	raycast->delta_dist[1] = fabs(1 / raycast->ray_dir[1]);
}

void	set_side(t_raycast *raycast, t_data *data)
{
	if (raycast->ray_dir[0] < 0)
		raycast->side_dist[0] = (data->player.pos_x - raycast->map[0])
			* raycast->delta_dist[0];
	else
		raycast->side_dist[0] = (raycast->map[0] + 1.0 - data->player.pos_x)
			* raycast->delta_dist[0];
	if (raycast->ray_dir[1] < 0)
		raycast->side_dist[1] = (data->player.pos_y - raycast->map[1])
			* raycast->delta_dist[1];
	else
		raycast->side_dist[1] = (raycast->map[1] + 1.0 - data->player.pos_y)
			* raycast->delta_dist[1];
}

void	set_step(t_raycast *raycast, t_data *data)
{
	if (raycast->ray_dir[0] < 0)
		raycast->step[0] = -1;
	else
		raycast->step[0] = 1;
	if (raycast->ray_dir[1] < 0)
		raycast->step[1] = -1;
	else
		raycast->step[1] = 1;
}

void	set_dda(t_raycast *raycast, t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->side_dist[0] < raycast->side_dist[1])
		{
			raycast->side_dist[0] += raycast->delta_dist[0];
			raycast->map[0] += raycast->step[0];
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist[1] += raycast->delta_dist[1];
			raycast->map[1] += raycast->step[1];
			raycast->side = 1;
		}
		if (data->map[raycast->map[0]][raycast->map[1]] > 0)
			hit = 1;
	}
}

void	set_walls(t_raycast *raycast)
{
	if (raycast->side == 0)
		raycast->perp_wall_dist = (raycast->side_dist[0]
			- raycast->delta_dist[0]);
	else
		raycast->perp_wall_dist = (raycast->side_dist[1]
			- raycast->delta_dist[1]);

	raycast->line_height = (int)(W_HEIGHT / raycast->perp_wall_dist);

	raycast->draw_start = -raycast->line_height / 2 + W_HEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + W_HEIGHT / 2;
	if (raycast->draw_end >= W_HEIGHT)
		raycast->draw_end = W_HEIGHT - 1;
}

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
		cur_tex = set_textures(x, &raycast, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
