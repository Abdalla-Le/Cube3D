/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:01:13 by ancarlos          #+#    #+#             */
/*   Updated: 2026/01/24 17:04:22 by ancarlos         ###   ########.fr       */
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