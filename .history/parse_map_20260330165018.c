/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_20260330165018.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:48:28 by ancarlos          #+#    #+#             */
/*   Updated: 2026/03/30 17:06:15 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

char	**no_newline(char	**matrix)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '\n')
				matrix[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (matrix);
}


static int	verify_caracters(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[j])
	{
		i = 0;
		while (matrix[j][i])
		{
			if (!ft_strchr("0 1NWSE", matrix[j][i]))
			{
				printf("Error\nInvalid character found in map. Allowed characters: '0', '1', 'N', 'S', 'E', 'W' or spaces.");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}


static int	find_player(t_map *map)
{
	int	y;
	int	x;
	int	player_count;

	player_count = 0;
	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (handle_position(map->grid[y][x], map, y, x))
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		printf("Error\nMap must have exactly one player start position (N, S, E, or W).\n");
		return (0);
	}
	get_width(map);
	printf("%d", map->width);
	return (1);
}

int parse_map(t_map *map)
{
	map->grid = no_newline(map->grid);
	if ((!verify_caracters(map->grid)) || (!find_player(map)))
		return (0);
	normalize_grid(map);
	if (!validate_wall(map))
		return (0);
	return (1);
}
