/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:53:29 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 15:39:50 by eteofilo         ###   ########.fr       */
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

// void	draw_vertical_line(t_data *data, int x, int draw_start, int draw_end, int color)
// {
// 	int	y;

// 	y = draw_start;
// 	while (y < draw_end)
// 	{
// 		my_mlx_pixel_put(data, x, y, color);
// 		y++;
// 	}
// }

void	paint(t_data *data)
{
	for (int i = 0; i < W_HEIGHT / 2; i++)
		for (int j = 0; j < W_WIDTH; j++)
			my_mlx_pixel_put(data, j, i, data->real_map.ceil_color);
	for (int i = W_HEIGHT / 2; i < W_HEIGHT; i++)
		for (int j = 0; j < W_WIDTH; j++)
			my_mlx_pixel_put(data, j, i, data->real_map.floor_color);
}

void	init_data(t_data *data, t_map *map)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, W_WIDTH, W_HEIGHT, "Cub3D Leticia");
	data->img.img_ptr = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(
			data->img.img_ptr,
			&data->img.bpp,
			&data->img.line_len,
			&data->img.endian);
	data->real_map = *map;
	data->map = convert_grid(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	if (ac != 2)
	{
		printf("Error\nUso correto: ./cub3D <mapa.cub>\n");
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
