/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:16:25 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/23 16:29:38 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	find_color(char *line, t_map file)
{
	if (line[0] == 'C' || line[0] == 'F')
	{
		if (line[0] == 'C')
			file.ceil_color = ft_strdup(line);
		else
			file.floor_color = ft_strdup(line);
		return (1);
	}
	return (0);
}

int	find_way(char *line, t_map file)
{
	if (line[0] == 'E' || line[0] == 'W' || line[0] == 'S' || line[0] == 'N' )
	{
		if (line[0] == 'E')
			file.ea_path = ft_strdup(line);
		if (line[0] == 'W')
			file.we_path = ft_strdup(line);
		if (line[0] == 'S')
			file.so_path = ft_strdup(line);
		if (line[0] == 'O')
			file.no_path = ft_strdup(line);
		return (1);
	}
	return (0);
}


int	path_way(int fd, t_map file, char *line)
{
	char	*line;

	
	if (line[0] >= 65 && line[0] <= 90)
	{
		if (!find_color(line, file) && !find_way(line, file))
			return 0;
	}
    return (1);
}