/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:40:00 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 13:45:10 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void set_raycast(int x, t_raycast *raycast, t_data *data)
{
		camera_x = 2 * x / (double)W_WIDTH - 1;
		raycast->ray_dir[0] = data->player.dir_x + data->player.plane_x * camera_x;
		raycast->ray_dir[1] = data->player.dir_y + data->player.plane_y * camera_x;

		raycast->map[0] = (int)data->player.pos_x;
		raycast->map[1] = (int)data->player.pos_y;

		raycast->delta_dist[0] = fabs(1 / raycast->ray_dir[0]);
		raycast->delta_dist[1] = fabs(1 / raycast->ray_dir[1]);
}

int	raycasting_loop(t_data *data)
{
	int			x;
	double		camera_x;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_raycast	raycast;

	paint(data);
	x = 0;
	while (x < W_WIDTH)
	{
		set_raycast(x, &raycast, data);

		if (raycast.ray_dir[0] < 0)
		{
			raycast.step[0] = -1;
			raycast.side_dist[0] = (data->player.pos_x - raycast.map[0]) * raycast.delta_dist[0]; // pos_x - raycast.map[0] = posição real dentro do bloco; * raycast.delta_dist = distância real até o limite do bloco
		}
		else
		{
			raycast.step[0] = 1;
			raycast.side_dist[0] = (raycast.map[0] + 1.0 - data->player.pos_x) * raycast.delta_dist[0];
		}
		if (raycast.ray_dir[1] < 0)
		{
			raycast.step[1] = -1;
			raycast.side_dist[1] = (data->player.pos_y - raycast.map[1]) * raycast.delta_dist[1];
		}
		else
		{
			raycast.step[1] = 1;
			raycast.side_dist[1] = (raycast.map[1] + 1.0 - data->player.pos_y) * raycast.delta_dist[1];
		}

		// --- DDA (Achar Parede) ---
		hit = 0;
		while (hit == 0)
		{
			if (raycast.side_dist[0] < raycast.side_dist[1])
			{
				raycast.side_dist[0] += raycast.delta_dist[0];
				raycast.map[0] += raycast.step[0];
				side = 0;
			}
			else
			{
				raycast.side_dist[1] += raycast.delta_dist[1];
				raycast.map[1] += raycast.step[1];
				side = 1;
			}
			if (data->map[raycast.map[0]][raycast.map[1]] > 0)
				hit = 1;
		}

		// --- CÁLCULO FINAL ---
		if (side == 0)
			perp_wall_dist = (raycast.side_dist[0] - raycast.delta_dist[0]); //subtrai um passo
		else
			perp_wall_dist = (raycast.side_dist[1] - raycast.delta_dist[1]);

		line_height = (int)(W_HEIGHT / perp_wall_dist);

		draw_start = -line_height / 2 + W_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + W_HEIGHT / 2;
		if (draw_end >= W_HEIGHT)
			draw_end = W_HEIGHT - 1;

		int tex_index;
		if (side == 0)
			tex_index = (raycast.ray_dir[0] > 0) ? 2 : 3;
		else
			tex_index = (raycast.ray_dir[1] > 0) ? 0 : 1;

		t_img *cur_tex = &data->tex_test[tex_index];


		double wall_x;
		if (side == 0)
			wall_x = data->player.pos_y + perp_wall_dist * raycast.ray_dir[1];
		else
			wall_x = data->player.pos_x + perp_wall_dist * raycast.ray_dir[0];
		wall_x -= floor(wall_x);

		int tex_x = (int)(wall_x * (double)TEX_W);
		if ((side == 0 && raycast.ray_dir[0] > 0) || (side == 1 && raycast.ray_dir[1] < 0))
			tex_x = TEX_W - tex_x - 1;

		for (int y = draw_start; y < draw_end; y++)
		{
			int d     = y * 256 - W_HEIGHT * 128 + line_height * 128;
			int tex_y = ((d * TEX_H) / line_height) / 256;
			int color = *(int *)(cur_tex->addr
						+ tex_y * cur_tex->line_len
						+ tex_x * (cur_tex->bpp / 8));

			my_mlx_pixel_put(data, x, y, color);
		}
		x++;
	}

	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
