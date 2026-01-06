/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:06:09 by ancarlos          #+#    #+#             */
/*   Updated: 2026/01/06 14:08:22 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int parse_file(int fd, t_map *file, t_gnl **lst)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] >= 65 && line[i] <= 90)
			path_way(fd, file, line);
		if (line[i] >= '0' && line[i] <= '9')
			parse_map(fd, file, line, lst);
		i = 0;
		free(line);
	}
	return (1);
}
