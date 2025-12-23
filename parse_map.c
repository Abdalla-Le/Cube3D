/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:06:09 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/23 16:29:39 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int parse_file(int fd, t_map file)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
    {
		if (line[0] >= 65 && line[0] <= 90)
			path_way(fd, file, line);
		if (line[0] >= '0' && line[0] <= '9')

		free(line);
	}
	return 1;
}	