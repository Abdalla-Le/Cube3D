/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_way_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:12:58 by ancarlos          #+#    #+#             */
/*   Updated: 2026/03/25 16:14:47 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_clean_path(char *line)
{
	char	*path;
	int		i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	i += 2; 
	while (line[i] && line[i] == ' ')
		i++;
	path = ft_strtrim(&line[i], " \n");
	return (path);
}


int	take_color(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | (b));
}