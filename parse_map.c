/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:48:28 by ancarlos          #+#    #+#             */
/*   Updated: 2026/01/20 16:10:48 by ancarlos         ###   ########.fr       */
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


int	verify_caracters(char **matrix)
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

int parse_map(t_map *map)
{
	map->grid = no_newline(map->grid);
	if (!verify_caracters(map->grid))
		return (0);
	return (1);
}