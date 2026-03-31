/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:45:43 by ancarlos          #+#    #+#             */
/*   Updated: 2026/03/31 14:45:47 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static int	flood_fill_plus(t_map *map, char **temp_grid, int y, int x)
{
	if (y < 0 || y >= map->height || x < 0 || x >= map->width)
		return (0);
	if (temp_grid[y][x] == ' ')
		return (0);
	if (temp_grid[y][x] == '1' || temp_grid[y][x] == 'V')
		return (1);
	temp_grid[y][x] = 'V';
	if (!flood_fill_plus(map, temp_grid, y + 1, x)
		||!flood_fill_plus(map, temp_grid, y - 1, x)
		||!flood_fill_plus(map, temp_grid, y, x + 1)
		||!flood_fill_plus(map, temp_grid, y, x - 1))
		return (0);
	return (1);
}

static char	**copy_matrix(t_map *map)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		copy[y] = malloc(sizeof(char) * (map->width + 1));
		if (!copy[y])
			return (NULL);
		ft_memcpy(copy[y], map->grid[y], map->width + 1);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

int	validate_wall(t_map *map)
{
	int		is_valid;
	char	**temp_grid;

	temp_grid = copy_matrix(map);
	is_valid = flood_fill_plus(map, temp_grid, map->p_y, map->p_x);
	my_free_matrix(temp_grid);
	if (!is_valid)
		printf("Error\n Map is open! Walls must to be closed\n");
	return (is_valid);
}
