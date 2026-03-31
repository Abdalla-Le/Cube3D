/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:39:09 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 15:39:56 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	is_wall(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_size[1] || y >= data->map_size[0])
		return (1);
	return (data->map[x][y] != 0);
}
