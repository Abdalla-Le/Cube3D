/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:48:28 by ancarlos          #+#    #+#             */
/*   Updated: 2026/01/19 20:49:43 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

int parse_map(t_map *map)
{
	map->grid = no_newline(map->grid);
	return (1);
}