/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_way->c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:16:25 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/23 18:19:08 by ancarlos         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	find_color(char *line, t_map *file)
{
	(void)line;
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'C' || line[i] == 'F')
	{
		if (line[i] == 'C')
			file->ceil_color = 3;//ft_strdup(line);
		else
			file->floor_color = 3;//ft_strdup(line);
		return (1);
	}
	return (0);
}

static int	find_way(char *line, t_map *file)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'E' || line[i] == 'W' || line[i] == 'S' || line[i] == 'N' )
	{
		if (line[i] == 'E')
			file->ea_path = ft_strdup(line);
		if (line[i] == 'W')
			file->we_path = ft_strdup(line);
		if (line[i] == 'S')
			file->so_path = ft_strdup(line);
		if (line[i] == 'N')
			file->no_path = ft_strdup(line);
		return (1);
	}
	return (0);
}

int	path_way(int fd, t_map *file, char *line)
{
	(void)fd;
	if ((line[0] >= 65 && line[0] <= 90) || line[0] == ' ')
	{
		if (!find_color(line, file) && !find_way(line, file))
			return 0;
	}
	return (1);
}
