/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:22:42 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 13:23:02 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_len(t_data *data)
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

int	**convert_grid(t_data *data)
{
	int	i;
	int	j;
	int	**int_grid;

	map_len(data);
	int_grid = malloc(sizeof(int *) * data->map_size[1]);
	if (!int_grid)
		return (NULL);
	i = 0;
	while (data->real_map.grid[i] != NULL)
	{
		int_grid[i] = malloc(sizeof(int) * data->map_size[0]);
		j = 0;
		while (data->real_map.grid[i][j] != '\0')
		{
			if (data->real_map.grid[i][j] == '1'
				|| data->real_map.grid[i][j] == ' ')
				int_grid[i][j++] = 1;
			else
				int_grid[i][j++] = 0;
		}
		i++;
	}
	int_grid[i] = NULL;
	return (int_grid);
}
