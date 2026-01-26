/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:01:13 by ancarlos          #+#    #+#             */
/*   Updated: 2026/01/25 21:19:08 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int check_params(t_map *map)
{
	return (map->no_path && map->so_path && map->we_path && 
			 map->ea_path && map->floor_color > -1 && map->ceil_color > -1);
}

int	handle_position(char c, t_map *map, int y, int x)
{
	if (ft_strchr("NSEW", c))
	{
		map->p_x = x;
		map->p_y = y;
		map->p_dir = c;
		return (1);
	}
	return (0);
}

void	get_width(t_map *map)
{
	int j;
	int len;

	j = 0;
	map->width = 0;
	while (map->grid[j])
	{
		len = ft_strlen(map->grid[j]);
		if (len > map->width)
		map->width = len;
		j++;
	}
}

void	normalize_grid(t_map *map)
{
	char	**new_grid;
	int		y;
	int		original_len;

	new_grid = malloc(sizeof(char **) * (map->height + 1));
	y = 0;
	while (y < map->height)
	{
		new_grid[y] = malloc(sizeof(char *) * (map->width + 1));
		ft_memset(new_grid[y], ' ', map->width);
		new_grid[y][map->width] = 0;
		original_len = ft_strlen(map->grid[y]);
		ft_memcpy(new_grid[y], map->grid[y], original_len);
		y++;
	}
	new_grid[y] = NULL;
	my_free_matrix(map->grid);
	map->grid = new_grid;
}