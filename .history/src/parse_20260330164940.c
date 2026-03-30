/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:31:59 by ancarlos          #+#    #+#             */
/*   Updated: 2026/03/30 16:49:41 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parse.h"

static void	init_struct(t_map *map)
{
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->floor_color = -1;
	map->ceil_color = -1;
	map->grid = NULL;
}

static int	process_data(int fd, t_map *map_data, t_gnl **lst_temp)
{
	if (!parse_file(fd, map_data, lst_temp))
	{
		close(fd);
		return (0);
	}
	close(fd);
	map_data->grid = fill_matrix(lst_temp, map_data);
	if (!map_data->grid)
		return (0);
	return (1);
}

t_map	*init_parse(char *file_name)
{
	t_map	*map_data;
	t_gnl	*lst_temp;
	int		fd;

	lst_temp = NULL;
	fd = stdin_parse(file_name);
	if (fd < 0)
		return (NULL);
	map_data = malloc(sizeof(t_map));
	if (!map_data)
		return (close(fd), NULL);
	init_struct(map_data);
	if (!process_data(fd, map_data, &lst_temp))
	{
		free_map_struct(map_data);
		return (NULL);
	}
	if (!parse_map(map_data))
	{
		free_map_struct(map_data);
		return (NULL);
	}
	return (map_data);
}
