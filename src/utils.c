/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:39:09 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 21:15:35 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#ifdef __APPLE__

static void	destroy_display(void *mlx)
{
	(void)mlx;
}
#else

static void	destroy_display(void *mlx)
{
	if (mlx)
		mlx_destroy_display(mlx);
}

#endif

int	close_window(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i] != NULL)
			free(data->map[i++]);
		free(data->map);
	}
	free_map_fields(&data->real_map);
	free(data->map_to_free);
	i = 0;
	while (i < 4)
	{
		if (data->tex_test[i].img_ptr)
			mlx_destroy_image(data->mlx, data->tex_test[i].img_ptr);
		i++;
	}
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	is_wall(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_size[1] || y >= data->map_size[0])
		return (1);
	return (data->map[x][y] != 0);
}
