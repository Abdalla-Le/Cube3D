/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_20260331143941.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:24:56 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 19:57:10 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_texture(t_data *data)
{
	int	w;
	int	h;
	int	i;

	data->tex_test[0].img_ptr = mlx_xpm_file_to_image(
			data->mlx, data->real_map->no_path, &w, &h);
	data->tex_test[1].img_ptr = mlx_xpm_file_to_image(
			data->mlx, data->real_map->so_path, &w, &h);
	data->tex_test[2].img_ptr = mlx_xpm_file_to_image(
			data->mlx, data->real_map->we_path, &w, &h);
	data->tex_test[3].img_ptr = mlx_xpm_file_to_image(
			data->mlx, data->real_map->ea_path, &w, &h);
	i = 0;
	while (i < 4)
	{
		data->tex_test[i].addr = mlx_get_data_addr(data->tex_test[i].img_ptr,
				&data->tex_test[i].bpp,
				&data->tex_test[i].line_len,
				&data->tex_test[i].endian);
		i++;
	}
}

static int	set_tex_x(t_raycast *raycast, t_data *data)
{
	double	wall_x;

	if (raycast->side == 0)
		wall_x = data->player.pos_y
			+ raycast->perp_wall_dist * raycast->ray_dir[1];
	else
		wall_x = data->player.pos_x
			+ raycast->perp_wall_dist * raycast->ray_dir[0];
	wall_x -= floor(wall_x);
	return ((int)(wall_x * (double)TEX_W));
}

static void	paint_textures(t_img cur_tex,
	int x, t_raycast *raycast, t_data *data)
{
	int		d;
	int		tex[2];
	int		color;
	int		i;

	tex[0] = set_tex_x(raycast, data);
	if ((raycast->side == 0 && raycast->ray_dir[0] > 0)
		|| (raycast->side == 1 && raycast->ray_dir[1] < 0))
		tex[0] = TEX_W - tex[0] - 1;
	i = raycast->draw_start;
	while (i < raycast->draw_end)
	{
		d = i * 256 - W_HEIGHT * 128 + raycast->line_height * 128;
		tex[1] = ((d * TEX_H) / raycast->line_height) / 256;
		color = *(int *)(cur_tex.addr
				+ tex[1] * cur_tex.line_len
				+ tex[0] * (cur_tex.bpp / 8));
		my_mlx_pixel_put(data, x, i, color);
	}
}

void	set_textures(int x, t_raycast *raycast, t_data *data)
{
	int		tex_index;
	t_img	cur_tex;

	if (raycast->side == 0)
	{
		if (raycast->ray_dir[0] > 0)
			tex_index = 2;
		else
			tex_index = 3;
	}
	else
	{
		if (raycast->ray_dir[1] > 0)
			tex_index = 0;
		else
			tex_index = 1;
	}
	paint_textures(data->tex_test[tex_index], x, &raycast, data);
}
