/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:22:42 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 16:11:22 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	map_len(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map_size[0] = 0;
	while (data->real_map.grid[i] != NULL)
	{
		j = 0;
		while (data->real_map.grid[i][j] != '\0')
			j++;
		if (data->map_size[0] < j)
			data->map_size[0] = j;
		i++;
	}
	data->map_size[1] = i;
}

void set_grids(t_data *data, int i, int **int_grid)
{
	int	j;

	j = 0;
	while (data->real_map.grid[i][j] != '\0')
	{
		if (data->real_map.grid[i][j] == '0')
			int_grid[i][j++] = 0;
		else
			int_grid[i][j++] = 1;
	}
}

int	**convert_grid(t_data *data)
{
	int	i;
	int	j;
	int	**int_grid;

	map_len(data);
	int_grid = malloc(sizeof(int *) * (data->map_size[1] + 1));
	if (!int_grid)
		return (NULL);
	i = 0;
	while (data->real_map.grid[i] != NULL)
	{
		int_grid[i] = malloc(sizeof(int) * data->map_size[0]);
		if (!int_grid[i])
			return (NULL);
		j = 0;
		while (j < data->map_size[0])
			int_grid[i][j++] = 1;
		j = 0;
		set_grids(data, i, int_grid);
		i++;
	}
	int_grid[i] = NULL;
	return (int_grid);
}
