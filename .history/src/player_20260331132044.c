/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_20260331132044.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:19:39 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 19:57:10 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	find_dir(t_data *data, char pos)
{
	if (pos == 'N')
	{
		data->player.dir_x = -1.0;
		data->player.dir_y = 0.0;
	}
	else if (pos == 'S')
	{
		data->player.dir_x = 1.0;
		data->player.dir_y = 0.0;
	}
	else if (pos == 'E')
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = 1.0;
	}
	else if (pos == 'W')
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = -1.0;
	}
}

static void	find_plane(t_data *data, char pos)
{
	if (pos == 'N')
	{
		data->player.plane_x = 0.0;
		data->player.plane_y = 0.66;
	}
	else if (pos == 'S')
	{
		data->player.plane_x = 0.0;
		data->player.plane_y = -0.66;
	}
	else if (pos == 'E')
	{
		data->player.plane_x = 0.66;
		data->player.plane_y = 0.0;
	}
	else if (pos == 'W')
	{
		data->player.plane_x = -0.66;
		data->player.plane_y = 0.0;
	}
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->real_map->grid[i] != NULL)
	{
		j = 0;
		while (data->real_map->grid[i][j] != '\0')
		{
			if (data->real_map->grid[i][j] == 'N'
				|| data->real_map->grid[i][j] == 'S'
				|| data->real_map->grid[i][j] == 'E'
				|| data->real_map->grid[i][j] == 'W')
			{
				data->player.pos_x = i + 0.5;
				data->player.pos_y = j + 0.5;
				find_dir(data, data->real_map->grid[i][j]);
				find_plane(data, data->real_map->grid[i][j]);
				data->real_map->grid[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
