/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:53:29 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 21:01:53 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/parse.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_data(t_data *data, t_map *map)
{
	int	i;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "cub3D");
	data->img.img_ptr = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(
			data->img.img_ptr,
			&data->img.bpp,
			&data->img.line_len,
			&data->img.endian);
	i = 0;
	while (i < 4)
	{
		data->tex_test[i].img_ptr = NULL;
		data->tex_test[i].addr = NULL;
		data->tex_test[i].bpp = 0;
		data->tex_test[i].line_len = 0;
		data->tex_test[i].endian = 0;
		i++;
	}
	data->real_map = *map;
	data->map_to_free = map;
	data->map = convert_grid(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	if (ac != 2)
	{
		printf("Error\nUsage: ./cub3D <map.cub>\n");
		return (1);
	}
	map = init_parse(av[1]);
	if (!map)
		return (1);
	init_data(&data, map);
	find_player(&data);
	load_texture(&data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, key_handler, &data);
	mlx_loop_hook(data.mlx, &raycasting_loop, &data);
	mlx_loop(data.mlx);
	free_map_struct(map);
	return (0);
}
