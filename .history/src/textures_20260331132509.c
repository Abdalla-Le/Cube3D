/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_20260331132509.c                          :+:      :+:    :+:   */
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
